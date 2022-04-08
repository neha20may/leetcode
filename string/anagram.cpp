//
// Created by neha2 on 11-02-2022.
//

#include <bits/stdc++.h>

using namespace std;

 //* Definition for a binary tree node.
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
class Solution {
public:
    bool checkPalindrome(deque<TreeNode*> q){
        auto i=q.begin(), j=q.end()-1;
        while(i<=j){
            cout<<(*i)->val<<endl;
            cout<<(*j)->val<<endl;
            if((*i)->val!=(*j)->val)
                return false;
            else
            {
                i++;j--;
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr || root->left==nullptr and root->right==nullptr)
            return true;
        else{
            deque<TreeNode*> q;
            q.push_back(root);
            while(!q.empty()){
                int n=q.size();
                //if q is palindrome
                if(checkPalindrome(q)){
                    for(int i=0;i<n;i++){
                        TreeNode *f=q.front();
                        if(f->left!=nullptr)
                            q.push_back(f->left);
                        if(f->right!=nullptr)
                            q.push_back(f->right);
                        q.pop_front();
                    }
                }
                else
                {
                    return false;
                }
            }
            return true;
        }

    }
};
int main(){
    //[5,4,6,null,null,3,7]
    TreeNode *l=new TreeNode(2, nullptr, new TreeNode(3, nullptr, nullptr));
    TreeNode *r=new TreeNode(2, nullptr,new TreeNode(3, nullptr, nullptr));
    TreeNode *root=new TreeNode(1, l, r);
    Solution s;
    s.isSymmetric(root);
}