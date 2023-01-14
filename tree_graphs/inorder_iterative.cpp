//
// Created by Neha Dubey on 09/01/23.
//

#include "vector"
#include "iostream"
#include "stack"
#include "unordered_map"
using namespace  std;
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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root== nullptr)
            return vector<int>();

        stack<TreeNode*> s;
        vector<int> result;
        unordered_map<TreeNode*, bool> visited;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top();
            cout<<"size="<<s.size()<<endl;
            cout<<"node= "<<node->val<<" "<<endl;
            s.pop();
            if(visited[node]){
                result.push_back(node->val);
                continue;
            }else{
                visited[node]=true;
                if(node->right!=nullptr){
                    s.push(node->right);
                }
                s.push(node);
                if(node->left!=nullptr){
                    s.push(node->left);
                }

            }
        }
        return result;
    }
};
int main(){
    TreeNode *root = new TreeNode(1,
                                  nullptr,
                                  new TreeNode(2, new TreeNode(3, nullptr, nullptr), nullptr));
    root= nullptr;
    Solution s;
    auto result= s.inorderTraversal(root);
    for(auto x: result){
        cout<<x<<" ";
    }
    cout<<endl;

}