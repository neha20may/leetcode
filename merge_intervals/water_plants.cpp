//
// Created by neha2 on 16-04-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct comp {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return (a.first < b.first);
        }
    };

public:

    bool overlap(pair<int, int> &a, pair<int, int> &b) {
        return (a.first <= b.first && b.first < a.second);
    }

    pair<int, int> combine(pair<int, int> &a, pair<int, int> &b) {
        pair<int, int> c;
        c.first = a.first;
        c.second = max(a.second, b.second);
        return c;
    }

    vector<pair<int, int>> merge(vector<pair<int, int>> &intervals) {
        int n = intervals.size();
        vector<pair<int, int>> ans;
        int start = intervals[0].first;
        int end = intervals[0].second;
        for (int i = 1; i < n; i++) {
            if (overlap(intervals[i - 1], intervals[i])) {
                auto mInterval = combine(intervals[i - 1], intervals[i]);
                cout<<"merged interval "<<mInterval.first<<" "<<mInterval.second<<endl;
                end = mInterval.second;
            } else {
                ans.push_back(make_pair(start, end));
                start = intervals[i].first;
                end = intervals[i].second;
            }
        }
        ans.push_back(make_pair(start, end));
        return ans;
    }

    void print(vector<pair<int, int>> intervals) {
        for (auto i: intervals) {
            cout << i.first << ", " << i.second << endl;
        }
    }

    int minTaps(int n, vector<int> &ranges) {
        typedef pair<int, int> interval;
        vector<interval> intervals;
        for (int i = 0; i <= n; i++) {
            intervals.push_back(make_pair(i - ranges[i], i + ranges[i]));
        }
        comp cmp;
        sort(intervals.begin(), intervals.end(), cmp);
        print(intervals);
        vector<pair<int, int>> m = merge(intervals);
        cout << "merged intervals " << endl;
        print(m);
        int ans = m.size();
        return ans;
    }
};

int main() {
    Solution sl;
    vector<int> ranges = {0,1,0,1};
    sl.minTaps(3, ranges);
}
