//
// Created by neha2 on 19-05-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<priority_queue<string,vector<string>, greater<string>>> createAdjList(vector<vector<string>> &tickets,
                                                 unordered_map<string, int> &map) {
        int N = tickets.size();
        int v = 0;
        for (int i = 0; i < tickets.size(); i++) {
            auto ticket = tickets[i][0];
            if(map.find(ticket)==map.end())
                map[ticket]=v++;
        }
        vector<priority_queue<string,vector<string>, greater<string>>> adj;
        adj.resize(map.size());
        for (auto ticket: tickets) {
            cout << "processing ticket " << ticket[0] << " -> " << ticket[1] << endl;
            adj[map[ticket[0]]].push(ticket[1]);
        }
        return adj;

    }

    void dfs(string key, unordered_map<string, bool> map) {


    }

    vector<string> findItinerary(vector<vector<string>> &tickets) {
        //create adjacent list
        vector<priority_queue<string,vector<string>, greater<string>>> adjList;
        unordered_map<string, int> map;
        adjList = createAdjList(tickets, map);
        //trvael list  and o/p
        int start = map["JFK"];
        vector<string> ans;
        ans.push_back("JFK");
        int NEdges=tickets.size();
        unordered_map<string, bool> edgeVisited;
        dfs("JFK", edgeVisited);
        int end=-1;
//        while ( start!= end) {
//            auto pq = adjList.begin() + start;
//            string next;
//            if (!pq->empty()) {
//                next = pq->top();
//                ans.push_back(next);
//                pq->pop();
//            }
//            end=start;
//            start = map[next];
//        }
        copy(ans.begin(), ans.end(), ostream_iterator<string>(cout, " "));
        cout << endl;
        return ans;
    }
};

int main() {
    vector<vector<string >> tickets = {
            {"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}
    };
    Solution s;
    s.findItinerary(tickets);
}
