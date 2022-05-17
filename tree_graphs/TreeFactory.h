//
// Created by neha2 on 10-05-2022.
//

#ifndef LEETCODE_TREEFACTORY_H
#define LEETCODE_TREEFACTORY_H

#include "TreeNode.h"

using namespace std;

#include <bits/stdc++.h>
#include <cstring>

class TreeSerialise {
public:
    string postorder(TreeNode *root, string &op) {
        if (root == nullptr)
            return op;
        postorder(root->left, op);
        postorder(root->right, op);
        op += root->val;
        op += "#";
        return op;
    }

    string serialize(TreeNode *root) {
        TreeNode *cur;
        string op = "";
        op = postorder(root, op);
        cout << " tree encoded is = " << op << endl;
        op.pop_back();
        return op;
    };
};

class TreeFactory {
protected:
    TreeNode *root;
public:

    virtual TreeNode *createFactory() = 0;

    void setTree(TreeNode *r) {
        root = r;
    }
};

class TreeFactory1 : public TreeFactory {
public:
    TreeNode *helper(int lower, int upper, deque<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }
        int val = nums.back();

        if (val < lower || val > upper)
            return nullptr;

        nums.pop_back();

        TreeNode *root = new TreeNode(val);
        root->right = helper(val, upper, nums);
        root->left = helper(lower, val, nums);
        return root;
    };

    TreeNode *deserialize(string s) {
        if (s.empty())
            return nullptr;

        char *data = const_cast<char *>(s.c_str());

        deque<int> nums;

        char *token = strtok(data, "#");
        while (token) {
            string p = token;
            nums.push_back(stoi(p));
            token = strtok(nullptr, "#");
        }
        TreeNode *root = helper(INT_MIN, INT_MAX, nums);
        return root;
    };

    TreeFactory1(string data) {
        TreeNode *root = deserialize(data);
        setTree(root);
    }

    TreeNode *createFactory() {
        return root;
    }
};

class TreeFactory2 : public TreeFactory {
public:
    TreeNode *helper(int lower, int upper, deque<int> nums) {
        if (nums.empty()) {
            return nullptr;
        }
        int val = nums.back();

        if (val < lower || val > upper)
            return nullptr;

        nums.pop_back();

        TreeNode *root = new TreeNode(val);
        root->right = helper(val, upper, nums);
        root->left = helper(lower, val, nums);
        return root;
    };

    TreeNode *deserialize(vector<int> &v1, vector<int> &v2) {
        //very constrained case of vector of numbers. there is no delimiter here to tell when a substree ends and when a subtree begins.
        //so for that we need one post inorder and in-order or pre-order and in-order
        //TODO: implement tree from two vectors of post and pre, pre and in, in and post.
        if (v1.empty())
            return nullptr;

        deque<int> nums(v1.begin(), v1.end());
        TreeNode *root = helper(INT_MIN, INT_MAX, nums);
        return root;
    };

    TreeFactory2(vector<int> v1, vector<int> v2) {
        TreeNode *root = deserialize(v1, v2);
        setTree(root);
    }

    TreeNode *createFactory() {
        return root;
    }
};


#endif //LEETCODE_TREEFACTORY_H
