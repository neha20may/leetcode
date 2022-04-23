//
// Created by neha2 on 24-04-2022.
//
#include <bits/stdc++.h>

using namespace std;
// !What a question
class Solution {
    int MOD = 1e9 + 7;

    struct comp {
        bool operator()(const vector<int> &a, const vector<int> &b) {
            if (a[0] == b[0])
                return (a[1] < b[1]);
            return (a[0] < b[0]);
        }
    };

    struct compy {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
            return (a.first < b.first);
        }
    };

public:
    int rectangleArea(vector<vector<int>> &rectangles) {
        vector<vector<int>> events;

        for (auto rec: rectangles) {
            events.push_back(vector<int>({rec[0], 0, rec[1], rec[3]}));
            events.push_back(vector<int>({rec[2], 1, rec[1], rec[3]}));
        }
        comp cmp;
        sort(events.begin(), events.end(), cmp);
        long area = 0;
        long prev = INT_MIN;

//        compy cmpy;
        multiset<pair<int, int>, compy> y_tuples;

        for (auto event: events) {
            int curr = event[0];
            int close = event[1], y1 = event[2], y2 = event[3];
            long diff = (long) curr - prev;
            area += getArea(diff, y_tuples);
            if (close == 1) {
                remove(y_tuples, y1, y2);
            } else {
                pair<int, int> p = make_pair(y1, y2);
                y_tuples.insert(p);
            }
            prev = curr;

        }
        return area % MOD;
    }

    void remove(multiset<pair<int, int>, compy> &y_tuples, int y1, int y2) {
        pair<int, int> p = make_pair(y1, y2);
        auto it = y_tuples.find(p);
        auto b=it;
        auto right_it=it;
        while(b!=y_tuples.end()){
            if(b->first==y1 && b->second==y2){
                right_it=b;
                break;
            }else{
                b++;
            }
        }
        y_tuples.erase(right_it);//will this work?
    }

    int getArea(long diff, multiset<pair<int, int>, compy> &y_tuples) {
        long area = 0;
        long prev = INT_MIN;
        for (auto yt: y_tuples) {
            long y1 = yt.first, y2 = yt.second;
            prev = max(prev, y1);
            long temp = ((y2 - prev) * diff)%MOD;
            area += max(temp, (long) 0);
            prev = max(prev, y2);
        }
        return area % MOD;
    }
};

int main() {
//    vector<vector<int>> rect = {{0, 0, 2, 2},
//                                {1, 0, 2, 3},
//                                {1, 0, 3, 1}};
    vector<vector<int>> rect = {{70, 53, 77, 77},
                                {25, 35, 68, 62},
                                {52, 35, 57, 83}};
    //[[70,53,77,77],[25,35,68,62],[52,35,57,83]]
    Solution sl;
    cout << "area=" << sl.rectangleArea(rect);
}

