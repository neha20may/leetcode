//
// Created by neha2 on 10-05-2022.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "TreeNode.h"
#include "TreeFactory.h"
#include "TreeSuccessor.h"
#include <bits/stdc++.h>

using namespace std;


class Solution {


public:
    TreeNode * root;
    TreeNode *treeToDoublyList(TreeNode *cur, TreeSuccessor *ts, TreeNode *&head) {
        if (cur == nullptr) {
            return nullptr;
        }
        if (cur->left == nullptr && cur->right == nullptr & head == nullptr) {
            head = cur;
            return head;
        }

        TreeNode *suc = ts->inorderSuccessor(root, cur);
        TreeNode *pred = ts->inorderPredecessor(root, cur);
        TreeNode *leftresult = treeToDoublyList(cur->left, ts, head);
        TreeNode *rightresult = treeToDoublyList(cur->right, ts, head);
        cur->left = pred;
        cur->right = suc;
        return cur;
    }
};

int main() {
    vector<int> v = {1, 2, 3};
    TreeFactory1 *tf = new TreeFactory1("1#3#2#5#4#7#9#8#6");
    TreeNode *root = tf->createFactory();
    TreeNode *node = find(root, 6);
    TreeSuccessor *ts = new TreeSuccessor();
    TreeNode *suc = ts->inorderSuccessor(root, node);
    cout << "inorder successor of node =" << node->val << " is =" << suc->val << endl;
    TreeNode *pred = ts->inorderPredecessor(root, node);
    cout << "inorder predecessor of node =" << node->val << " is =" << pred->val << endl;
    Solution s;
    TreeNode *head = nullptr;
    s.root=root;
    s.treeToDoublyList(root, ts,head);
    cout << "printing list ";
    while (head) {
        cout << head->val << " ";
        head = head->right;
    }
    cout << endl;


}

