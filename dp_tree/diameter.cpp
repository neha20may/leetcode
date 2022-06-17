//
// Created by neha2 on 08-06-2022.
//
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution1522 {
public:
    unordered_map<Node*, int> downPath;
    unordered_map<Node*, int> dm;

    void eval_downPath(Node* src, Node* par){
        int bestChildDownPath=0;
        bool leaf=1;
        for(Node * child: src->children){
            if(child!=par){
                leaf=0;
                eval_downPath(child, src);
                bestChildDownPath=max(bestChildDownPath, downPath[child]);
            }
        }
        if(leaf) downPath[src]=0;
        else downPath[src]=1+bestChildDownPath;
    }
    void solve(Node* src, Node* par){
        int ans=0;
        vector<int> childrenDownPaths;
        for(Node * child: src->children){
            if(child!=par){
                solve(child, src);
                childrenDownPaths.push_back(downPath[child]);
                ans=max(ans, dm[child]);
            }
        }

        int numOfChildren=childrenDownPaths.size();
        sort(childrenDownPaths.begin(),childrenDownPaths.end());

        if(numOfChildren==0) dm[src]=0;
        else if(numOfChildren==1) dm[src]=1+childrenDownPaths[0];
        else dm[src]=2+childrenDownPaths[numOfChildren-1]+childrenDownPaths[numOfChildren-2];

        dm[src]=max(dm[src], ans);
    }
    int diameter(Node* root) {
        eval_downPath(root, nullptr);
        solve(root, nullptr);
        int ans=dm[root];
        return ans;

    }
};


class Solution {
public:
    Node* makeTree(vector<vector<int>>& edges){
        unordered_set<int> st;
        for(auto e: edges){
            st.insert(e[0]);
            st.insert(e[1]);
        }
        unordered_map<int, Node*> nodes;
        for(auto n:st){
            Node * node= new Node(n);
            nodes[n]=node;
        }
        for(auto e1: edges){
            int u=e1[0];
            vector<Node*> children;
            for(auto e2:edges){
                if(e1!=e2){
                    if(e2[0]!=u){
                        int v=e2[1];
                        children.push_back(nodes[v]);
                    }else{
                        continue;
                    }

                }else{
                    continue;
                }
            }
            nodes[u]->children=children;
            children.clear();
        }
        return nodes[*st.begin()];

    }
    int treeDiameter(vector<vector<int>>& edges) {
        Node* root=makeTree(edges);

        Solution1522 sl;
        return sl.diameter(root);
    }
};
int main() {
    Solution sl;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    cout << sl.treeDiameter(edges) << endl;
    return 0;
}
