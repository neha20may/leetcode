//
// Created by Neha Dubey on 28/05/23.
//

#include "symmetricalTree.h"
#include "vector"
#include "iostream"
#include "stack"
#include "unordered_map"

using namespace std;

/**
 * Definition for a binary tree node.
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
/**
 1.   1.
2 3  3. 2.

left = right
right = left
at node you check left and right




**/
class Solution {
public:
    bool call(TreeNode *node, TreeNode *nodeRef) {
        cout << "enter" << ((node) ? node->val : -101) << " " << ((nodeRef) ? nodeRef->val : -101) << endl;
        if (node == nullptr & nodeRef == nullptr) {
            return true;
        }

        if (node != nullptr & nodeRef != nullptr & node->val == nodeRef->val) {
            bool a = false;
            bool b = false;
            if (node->left == nullptr & nodeRef->right == nullptr)
                a = true;

            if (node->left != nullptr & nodeRef->right != nullptr) {
                if (node->left->val == nodeRef->right->val) {
                    a = call(node->left, nodeRef->right);

                }
            }
            if (node->right == nullptr & nodeRef->left == nullptr)
                b = true;
            if (node->right != nullptr & nodeRef->left != nullptr) {
                if (node->right->val == nodeRef->left->val) {
                    b = call(node->right, nodeRef->left);
                }
            }
            return a & b;

        }
        return false;
    }

    bool isSymmetric(TreeNode *root) {
        return call(root, root);
    }
};

int main() {
    TreeNode *root = new TreeNode(1,
                                  new TreeNode(-42,
                                               nullptr,
                                               new TreeNode(76, nullptr, new TreeNode(13, nullptr, nullptr))),
                                  new TreeNode(-42,
                                               new TreeNode(76, nullptr, new TreeNode(13, nullptr, nullptr)),
                                               nullptr)

    );

    Solution s;
    auto result = s.isSymmetric(root);
    cout << result << endl;
    cout << endl;

}