

///
// Created by neha2 on 19-05-2022.
//
#include <bits/stdc++.h>

using namespace std;
class ValidPairs {
    int V;
    int E;
    vector<vector<int>> adj;
    unordered_map<int, int> map;
    unordered_map<int, int> rmap;
    vector<int> inDegree;
    vector<int> outDegree;
    vector<int> path;

public:
    void createAdjList(vector<vector<int>> &tickets) {
        int v = 0;
        for (int i = 0; i < tickets.size(); i++) {
            auto from = tickets[i][0];
            auto to=tickets[i][1];
            if (map.find(from) == map.end())
                map[from] = v++;
            if (map.find(to) == map.end())
                map[to] = v++;
        }
        for (auto p: map) {
            rmap[p.second] = p.first;
        }

        this->V = map.size();
        this->E = tickets.size();
        this->adj.resize(this->V);
        inDegree.resize(V, 0);
        outDegree.resize(V, 0);
        for (auto ticket: tickets) {
            int u = map[ticket[0]];
            int v = ticket[1];
            int vv = map[v];
            // cout << "processing ticket " << ticket[0] << " -> " << ticket[1] << endl;
            adj[u].push_back(v);
            inDegree[vv]++;
            outDegree[u]++;
        }

    }

    bool graphHasEulerPath() {
        int start_nodes=0, end_nodes = 0;
        for (int i = 0; i < V; i++) {
            if (outDegree[i] - inDegree[i] > 1 || inDegree[i] - outDegree[i] > 1)
                return false;
            else if (outDegree[i] - inDegree[i] == 1)
                start_nodes++;
            else if (inDegree[i] - outDegree[i] == 1)
                end_nodes++;
        }
        if (end_nodes == 0 && start_nodes == 0 || end_nodes == 1 && start_nodes == 1) {
            return true;
        }
        return false;
    }
    //In euler path, if the odd degrees are there then there can be only 2 nodes with odd degrees,
    // one has to work as start node and other has to work as sink.
    /**
     * Example 1: a--> b ; out(a)=1 in(b)=1; both are odd degree nodes. one is start and other is sink
     * Example 2:       c<-- a --> b
     *                         <-- b
     *                         out(a)=2, in(a)=1; in(b)=1, out(b)=1 , in(c)=1
     *                         so start node is a and end node is c
     *
     *                        */
    int findStartNode() {
        int start = 0;
        for (int i = 0; i < V; i++) {
            //unique starting node
            if (outDegree[i] - inDegree[i] == 1)
                return i;
            //start at any node.
            if (outDegree[i] > 0)
                start = i;
        }
        return start;
    }

    int findEndNode() {
        int end = 0;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] - outDegree[i] == 1)
                return i;
            if (inDegree[i] > 0)
                end = i;
        }
        return end;
    }

    bool findEulerPath() {
        if (!graphHasEulerPath()) { return false; }

        dfs(findStartNode(), path); //general case
        // dfs(map["JFK"], path);
        //if graph is dixconnected no euler path
        if (path.size() == E + 1)
            return true;
        else
            return false;

    }

    //post order dfs
    void dfs(int i, vector<int> &path) {
        while (outDegree[i] != 0) {
            //options to select next edge
            //1. se;ecy next unvisited outgoing edge
            //2. in here the smallest lexicogrpahic unvisited outgoing edge.
            auto &pq = adj[i];
            int nextV = pq.back();
            pq.pop_back();
            outDegree[i]--;
            dfs(map[nextV], path);
        }
        path.push_back(i); // ! reverse it later
    }

    vector<int> findItinerary(vector<vector<int>> &tickets) {
        //create adjacent list
        createAdjList(tickets);
        vector<int> ans;
        if (findEulerPath()) {
            reverse(path.begin(), path.end());//reversed the post order dfs.
            for (auto p: path)
                ans.push_back(rmap[p]);
        } else {
            return vector<int>();
        }
        return ans;
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        vector<int> path=findItinerary(pairs);
        vector<vector<int>> ans;
        for(int i=0; i<path.size()-1; i++){
            vector<int> v;
            v.push_back(path[i]);
            v.push_back(path[i+1]);
            ans.push_back(v);

            v.clear();
        }
        return ans;
    }
};


class Solution {
    int V;
    int E;
    vector<priority_queue<string, vector<string>, greater<string>>> adj;
    unordered_map<string, int> map;
    unordered_map<int, string> rmap;
    vector<int> inDegree;
    vector<int> outDegree;
    vector<int> path;

public:
    void createAdjList(vector<vector<string>> &tickets) {
        int v = 0;
        for (int i = 0; i < tickets.size(); i++) {
            auto from = tickets[i][0];
            auto to=tickets[i][1];
            if (map.find(from) == map.end())
                map[from] = v++;
            if (map.find(to) == map.end())
                map[to] = v++;
        }
        for (auto p: map) {
            rmap[p.second] = p.first;
        }

        this->V = map.size();
        this->E = tickets.size();
        this->adj.resize(this->V);
        inDegree.resize(V, 0);
        outDegree.resize(V, 0);
        for (auto ticket: tickets) {
            int u = map[ticket[0]];
            string v = ticket[1];
            int vv = map[v];
            cout << "processing ticket " << ticket[0] << " -> " << ticket[1] << endl;
            adj[u].push(v);
            inDegree[vv]++;
            outDegree[u]++;
        }

    }

    bool graphHasEulerPath() {
        int start_nodes=0, end_nodes = 0;
        for (int i = 0; i < V; i++) {
            if (outDegree[i] - inDegree[i] > 1 || inDegree[i] - outDegree[i] > 1)
                return false;
            else if (outDegree[i] - inDegree[i] == 1)
                start_nodes++;
            else if (inDegree[i] - outDegree[i] == 1)
                end_nodes++;
        }
        if (end_nodes == 0 && start_nodes == 0 || end_nodes == 1 && start_nodes == 1) {
            return true;
        }
        return false;
    }
    //In euler path, if the odd degrees are there then there can be only 2 nodes with odd degrees,
    // one has to work as start node and other has to work as sink.
    /**
     * Example 1: a--> b ; out(a)=1 in(b)=1; both are odd degree nodes. one is start and other is sink
     * Example 2:       c<-- a --> b
     *                         <-- b
     *                         out(a)=2, in(a)=1; in(b)=1, out(b)=1 , in(c)=1
     *                         so start node is a and end node is c
     *
     *                        */
    int findStartNode() {
        int start = 0;
        for (int i = 0; i < V; i++) {
            //unique starting node
            if (outDegree[i] - inDegree[i] == 1)
                return i;
            //start at any node.
            if (outDegree[i] > 0)
                start = i;
        }
        return start;
    }

    int findEndNode() {
        int end = 0;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] - outDegree[i] == 1)
                return i;
            if (inDegree[i] > 0)
                end = i;
        }
        return end;
    }

    bool findEulerPath() {
        if (!graphHasEulerPath()) { return false; }

        dfs(findStartNode(), path);
        //if graph is dixconnected no euler path
        if (path.size() == E + 1)
            return true;
        else
            return false;

    }

    void dfs(int i, vector<int> &path) {
        while (outDegree[i] != 0) {
            //options to select next edge
            //1. se;ecy next unvisited outgoing edge
            //2. in here the smallest lexicogrpahic unvisited outgoing edge.
            auto &pq = adj[i];
            string nextV = pq.top();
            pq.pop();
            outDegree[i]--;
            dfs(map[nextV], path);
        }
        path.insert(path.begin(), i);
    }

    vector<string> findItinerary(vector<vector<string>> &tickets) {
        //create adjacent list
        createAdjList(tickets);
        vector<string> ans;
        if (findEulerPath()) {
            for (auto p: path)
                ans.push_back(rmap[p]);
        } else {
            return vector<string>();
        }
        return ans;
    }
};

int main() {
    vector<vector<string >> tickets = {
            {"a", "b"},
            {"a", "c"},
            {"b", "a"}
    };
    Solution s;
    vector<string> eulerPath=s.findItinerary(tickets);
    for(auto v: eulerPath)
        cout<<v<<" ";
    cout<<endl;
}
