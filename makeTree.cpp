//
// Created by neha2 on 14-02-2022.
//

#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void make_tree(TreeNode * & root, vector<int>::iterator low, vector<int>::iterator high){
        if(low+1==high)
        {
            return;
        }
        else if(low==high)
            return;
        else{
            auto mid=low+ (high-low)/2;
            TreeNode * node=new TreeNode(*mid, nullptr, nullptr);
            make_tree(node->left, low,mid);
            make_tree(node->right, mid, high);
            root=node;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return nullptr;
        else if(nums.size()==1)
        {
            TreeNode * root=new TreeNode(nums[0], nullptr, nullptr);
            return root;
        }
        else{
            int mid=nums.size()/2;
            TreeNode * root=new TreeNode(nums[mid], nullptr, nullptr);
            make_tree(root->left, nums.begin(), nums.begin()+mid);
            make_tree(root->right, nums.begin()+mid, nums.end());
            return root;

        }
    }
};
int main(){
    vector<int> v={-10, -3, 0, 5,9};
    Solution s;
    TreeNode *root= s.sortedArrayToBST(v);
}
