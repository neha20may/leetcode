//
// Created by neha2 on 10-05-2022.
//
#include "TreeNode.h"

class TreeSuccessor {
    TreeNode *prev = nullptr, *suc = nullptr, * pred= nullptr;
public:
    TreeNode *leftMost(TreeNode *root) {
        while (root->left != nullptr)
            root = root->left;
        return root;
    }

    TreeNode *rightMost(TreeNode *root) {
        while (root->right != nullptr)
            root = root->right;
        return root;
    }

    void inorder(TreeNode *root, TreeNode *p) {
        if (root == nullptr)
            return;
        else {
            inorder(root->left, p);
            if (prev == p && suc == nullptr) {
                suc = root;
                return;
            }
            prev = root;
            inorder(root->right, p);
        }
    }
    void inorder2(TreeNode *root, TreeNode *p) {
        if (root == nullptr)
            return;
        else {
            inorder2(root->right, p);
            if (prev == p && pred == nullptr) {
                pred = root;
                return;
            }
            prev = root;
            inorder2(root->left, p);
        }
    }

    TreeNode *getS(TreeNode *root, TreeNode *p) {
        prev= nullptr;
        if (root == nullptr)
            return nullptr;
        else {
            if (p->right != nullptr)
                return leftMost(p->right);
            else {
                inorder(root, p);
                return suc;
            }
        }
    }

    TreeNode *getP(TreeNode *root, TreeNode *p) {
        prev= nullptr;
        if (root == nullptr)
            return nullptr;
        else {
            if (p->left != nullptr)
                return rightMost(p->left);
            else {
                inorder2(root, p);
                return pred;
            }
        }

    }

    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (root == nullptr)
            return nullptr;
        else
            return getS(root, p);

    }
    TreeNode *inorderPredecessor(TreeNode *root, TreeNode *p) {
        if (root == nullptr)
            return nullptr;
        else
            return getP(root, p);

    }
};