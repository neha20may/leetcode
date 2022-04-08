//
// Created by neha2 on 06-02-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkMerge(vector<int> &a, vector<int> &b) {
        return (a[1] >= b[0]) ? true : false;

    }

    vector<int> merge(vector<int> &a, vector<int> &b) {
        vector<int> t = {a[0]};
        if(a[1]>b[1])
            t.push_back(a[1]);
        else
            t.push_back(b[1]);
        return t;
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b) {
                 return (a[0] < b[0]) ? true : false;
             }
        );
        vector<vector<int>> merged_intervals;
        vector<int> big_interval = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (checkMerge(big_interval, intervals[i])) {
                big_interval = merge(big_interval, intervals[i]);
            } else {
                merged_intervals.push_back(big_interval);
                big_interval.clear();
                big_interval = intervals[i];
            }
        }
    }
};

int main() {
    vector<vector<int>> i = {{1,  3},
                             {2,  6},
                             {8,  10},
                             {15, 18}};
    Solution s;
    s.merge(i);
    return 0;
}

