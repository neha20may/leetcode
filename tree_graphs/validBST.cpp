//
// Created by Neha Dubey on 22/01/23.
//
/**
 * Definition for a binary tree node.*/
#include "vector"
#include "iostream"
#include "stack"
#include "unordered_map"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class result {
public:
    bool ans;
    TreeNode *min;
    TreeNode *max;

    result(bool an, TreeNode *a, TreeNode *b) : ans{an}, min{a}, max{b} {};
};

class Minmax {
public:
    long min, max;

    Minmax(long mn, long mx) : min{mn}, max{mx} {}

};

class Solution {
    /**
    case 1:
                a
            b       c
    case 2:
                a
            b
    case 3:
                a
                    c

    **/
public:
    result *firstAttempt(TreeNode *node) {
        if (node == nullptr) {
            return new result(true, nullptr, nullptr);
        }
        if (!node->left && !node->right) {
            return new result(true, node, node);
        }
        auto lr = firstAttempt(node->left);
        auto rr = firstAttempt(node->right);
        if (lr->ans && rr->ans) {
            auto lmin = lr->min;
            auto lmax = lr->max;
            auto rmin = rr->min;
            auto rmax = rr->max;
            if (lmin && lmax && rmin && rmax) {
                if (node->val > lmin->val && node->val > lmax->val && node->val < rmin->val && node->val < rmax->val) {
                    return new result(true, lmin, rmax);
                }
            } else if (lmin && lmax) {
                if (node->val > lmin->val && node->val > lmax->val) {
                    return new result(true, lmin, node);
                }
            } else if (rmin && rmax) {
                if (node->val < rmin->val && node->val < rmax->val) {
                    return new result(true, node, rmax);
                }
            }

        }
        return new result(false, node, node);

    };

    Minmax *isBST(TreeNode *node) {
        if (node == nullptr) {
            return new Minmax(LONG_MAX, LONG_MIN);
        }
        Minmax *left = isBST(node->left);
        Minmax *right = isBST(node->right);


        if (left == nullptr || right == nullptr) {
            return nullptr;
        }
        long min = left->min;
        long max = right->max;
        if (left->max >= node->val || right->min <= node->val) {
            return nullptr;
        } else {
            min = (min < node->val) ? min : node->val;
            max = (max > node->val) ? max : node->val;
        }
        return new Minmax(min, max);
    }

    bool isValidBST(TreeNode *root) {
        Minmax *r = isBST(root);
        if (r)
            return true;
        else
            return false;
    }
};