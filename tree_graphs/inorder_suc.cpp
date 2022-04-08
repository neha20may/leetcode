//
// Created by neha2 on 21-02-2022.
//

#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//    TreeNode *prev, *successor;
//public:
////    vector<TreeNode *> find(TreeNode * root, TreeNode *p){
////        if(root->val==p->val)
////            return vector<TreeNode*> {root, nullptr, nullptr};
////        else{
////            TreeNode * finder=root;
////            TreeNode * parent=nullptr, * grandparent=nullptr;
////            while(finder->val!=p->val){
////                if(finder->val > p->val)
////                {
////                    if(finder->left!=nullptr){
////                        grandparent=parent;
////                        parent=finder;
////                        finder=finder->left;
////                    }
////                    else{
////                        break;
////                    }
////
////                }
////                else{
////                    if(finder->right!=nullptr){
////                        grandparent=parent;
////                        parent=finder;
////                        finder=finder->right;
////                    }
////                    else{
////                        break;
////                    }
////
////                }
////            }
////            if(finder->val==p->val)
////            {
////                vector<TreeNode*> FP={finder, parent, grandparent};
////                return FP;
////            }
////            else
////            {
////                vector<TreeNode*> FP={nullptr, nullptr, nullptr};
////                return FP;
////            }
////
////
////        }
////    }
//    TreeNode *leftMost(TreeNode *root) {
//        while (root->left != nullptr)
//            root = root->left;
//        return root;
//    }
//
//    TreeNode *inorderTraversal(TreeNode *root, TreeNode *p) {
//        if (root == nullptr)
//            return nullptr;
//        else {
//            inorderTraversal(root->left, p);
//            if (prev == p && successor == nullptr) {
//                successor=root;
//                return successor;
//            }
//            prev = root;
//            inorderTraversal(root->right, p);
//
//        }
//
//    }
//
//    TreeNode *getS(TreeNode *root, TreeNode *p) {
//        if (root->val == p->val) {
//            if (root->right != nullptr)
//                return root->right;
//            else {
//                return nullptr;
//            };
//        }
//        //TODO: Note, this is a reference to p,
//        // so no need to find the root, the root is itself a reference.
//        //TODO: the parent and grandparent is essentially the inordder traversal of tree. That is crux of the question.
////        vector<TreeNode *> FP=find(root, p);
////        for(auto f:FP)
////            cout<<f<<" ";
////        cout<<endl;
////        if(*FP.begin()==nullptr)
////            return nullptr;
////        else{
////            TreeNode* finder=FP[0];
////            TreeNode *parent=FP[1];
////            TreeNode * gparent=FP[2];
////            if(finder->right!=nullptr)
////                return leftMost(finder->right);
////            else{
////                /**   gp
////                 *   /
////                 *  p
////                 *   \
////                 *    finder Case 1: gp is inorder successor
////                 *
////                 *
////                 */
////                if(parent->left==finder)
////                    return parent;
////                if(parent->right==finder){
////                    if(gparent!=nullptr && gparent->left==parent)
////                        return gparent;
////                    else
////                        return nullptr;
////                }
////            }
////            return nullptr;
////        }
//        if (p->right != nullptr)
//            return leftMost(p);
//        else {
//            return inorderTraversal(root, p);
//        }
//
//    }
//
//    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
//        if (root == nullptr)
//            return nullptr;
//        else
//            return getS(root, p);
//
//    }
//};
class Solution {
    TreeNode *prev=nullptr, *suc= nullptr;
public:
    TreeNode* leftMost(TreeNode*root){
        while(root->left!=nullptr)
            root=root->left;
        return root;
    }

    void inorder(TreeNode * root, TreeNode * p){
        if(root==nullptr)
            return;
        else{
            inorder(root->left, p);
            if(prev==p && suc==nullptr){
                suc=root;
                return;
            }
            prev=root;
            inorder(root->right, p);
        }
    }

    TreeNode * getS(TreeNode * root, TreeNode * p){
        if(root==nullptr)
            return nullptr;
        else{
            if(p->right!=nullptr)
                return leftMost(p);
            else{
                inorder(root, p);
                return suc;
            }
        }

    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==nullptr)
            return nullptr;
        else
            return getS(root, p);

    }
};
int main() {
    //2 1 3
    //[5,3,6,2,4,null,null,1]
    //6
    TreeNode *root = new TreeNode(2,
                                  nullptr,
                                  new TreeNode(3, nullptr, nullptr));
//    TreeNode * root=new TreeNode(0, nullptr, nullptr);
//    TreeNode* root=new TreeNode(5,
//                                new TreeNode(3,
//                                             new TreeNode(2,
//                                                          new TreeNode(1, nullptr, nullptr),
//                                                          nullptr),
//                                             new TreeNode(4, nullptr, nullptr)),
//                                new TreeNode(6, nullptr, nullptr));
    Solution s;
    TreeNode *p = root;
    s.inorderSuccessor(root, p);
}