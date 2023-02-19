//
// Created by neha2 on 26-11-2022.
//

#include "timeEnformEmployee.h"
#include "pickApples.h"
#include <bits/stdc++.h>
using namespace  std;
enum Status{unvisited, visiting, visited};
class Node{
public:
    int data;
    int takesTime;
    int distance=0;
    vector<Node*>neighbors;
    Status status =unvisited;

    vector<Node*> getN(){
        return neighbors;
    };
    void setNeighbor(vector<Node*> n){
        this->neighbors = n;
    };
    void setData(int d){
        this->data=d;
    };
    int getData(){
        return data;
    };
    void setApple(bool is){
        this->takesTime=is;
    }
    void addNeigh(Node* v){
        neighbors.push_back(v);
    }


};
class Graph{
public:
    vector<Node*> nodes;
    void setnodes(vector<Node*> n){
        this->nodes=n;
    }
    vector<Node*> getNodes(){
        return nodes;
    }
    void addNode(Node* n){
        nodes.push_back(n);
    }
    Node* getNode(int i){
        return nodes[i];
    }

};

Graph makeGraph(int n, int headId, vector<int> &manager, vector<int> &time){
    Graph g;
    Node * root;
    for(int i=0; i<n; i++){
        Node * node= new Node();
        node->setData(i);
        node->takesTime=time[i];
        if(i==headId)
            root=node;
        g.addNode(node);
    }
    for(int i=0; i<n ; i++){
        int m= manager[i];
        if(m!=-1){
            Node* manager = g.getNode(m);
            Node * subOrd= g.getNode(i);
            manager->addNeigh(subOrd);
        }
    }
    return g;

}

class Solution {
public:
    int dfsVisit(Node* node){
        node->status= visiting;
        int subOrdTime=0;
        for(auto n: node->getN()){
            if(n->status == unvisited){
                subOrdTime=max(subOrdTime,dfsVisit(n));
            }
        }
        node->takesTime+=subOrdTime;
        node->status= visited;
        return node->takesTime;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        Graph g= makeGraph(n, headID, manager, informTime);

        int ans= dfsVisit(g.getNode(headID));
        return ans;
    }
};
int main(){
    Solution s;
    int n=6;
    int headId=2;
    vector<int> manager={2,2,-1,2,2,2};
    vector<int> informTime={0,0,1,0,0,0};
    cout<<s.numOfMinutes(n, headId, manager,informTime)<<endl;
}