//
// Created by neha2 on 09-03-2022.
//
#include <bits/stdc++.h>
using namespace std;
class Vector2D {
    vector<vector<int>> myvec;
    pair<int, int> nexti;
    int m, n;
public:
    Vector2D(vector<vector<int>>& vec):myvec(vec) {
        nexti=make_pair(0,0);
        m=vec.size();
        n=myvec[0].size();
    }

    int next() {
        int i=nexti.first;
        int j=nexti.second;
        vector<int> v=myvec[i];
        i=i+


    }

    bool hasNext() {

    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */