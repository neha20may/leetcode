//
// Created by Neha Dubey on 24/12/22.
//
#include "iostream"
#include "vector"
using namespace  std;
enum Status{unvisited, visiting, visited};
class Node{
public:
    int data;
    bool hasApple;
    int distance=0;
    vector<Node*>neighbors;
    Status status;

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
        this->hasApple=is;
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
Graph makeGraph(int n, vector<vector<int>>& edges, vector<bool>& hasApple){
    Graph g;
    for(int i=0; i<n; i++){
        Node* n = new Node();
        n->setData(i);
        if(hasApple[i] ==true)
            n->setApple(true);
        else
            n->setApple(false);

        g.addNode(n);
    }
    for(auto edge:edges){
        auto f= edge[0];
        auto s= edge[1];
        Node* u= g.getNode(f);
        Node* v= g.getNode(s);
        u->addNeigh(v);
        v->addNeigh(u);
    }
    return g;

}

class Solution {
public:
    int dfsvisit(Node * node){
        node->status= visiting;
        for(auto neighbor: node->getN()){
            if(neighbor->status==unvisited)
                node->distance+=dfsvisit(neighbor);
        }

        node->status= visited;

        if(node->distance > 0){
            node->distance+=2;
        }else if(node->hasApple){
            return node->distance+=2;
        }

        return node->distance;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        Graph g=makeGraph(n, edges, hasApple);
        int ans= dfsvisit(g.getNode(0));
        if(ans > 0)
            return ans-2;
        return ans;
    }
};
int main(){
    int n = 7;
    vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    vector<bool> hasApple = {false,false,true,false,true,true,false};
    Solution s;
    int ans= s.minTime(n, edges, hasApple);
    cout<<"ans= "<<ans<<endl;
}