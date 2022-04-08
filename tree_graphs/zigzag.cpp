//
// Created by neha2 on 21-02-2022.
//

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution {
public:

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        } else if (inorder.size() == 1) {
            preorder.erase(preorder.begin()+0);
            return new TreeNode(inorder[0], nullptr, nullptr);
        } else {
            int index = 0;
            int val = preorder[index];
            TreeNode *root = new TreeNode(val, nullptr, nullptr);
            auto le = find(inorder.begin(), inorder.end(), val);
            vector<int> left_subtree_inorder = vector<int>(inorder.begin(), le);
            vector<int> right_subtree_inorder = vector<int>(le + 1, inorder.end());
            preorder.erase(preorder.begin() + index);
            root->left = buildTree(preorder, left_subtree_inorder);
            root->right = buildTree(preorder, right_subtree_inorder);
            return root;

        }


    }
};

int main() {
    //[3,9,20,15,7]
    //[9,3,15,20,7]
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> ino = {9, 3, 15, 20, 7};
    Solution s;
    TreeNode* root= s.buildTree(pre, ino);
}