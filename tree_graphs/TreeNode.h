//
// Created by neha2 on 21-02-2022.
//

#ifndef LEETCODE_TREENODE_H
#define LEETCODE_TREENODE_H

/**
 * Definition for a binary tree node.
 * **/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode * find(TreeNode *root, int key) {
    if (root == nullptr)
        return nullptr;
    if (root->val == key)
        return root;
    if (key < root->val)
        return find(root->left, key);
    else
        return find(root->right, key);
}

#endif //LEETCODE_TREENODE_H
