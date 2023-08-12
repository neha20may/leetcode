//
// Created by Neha Dubey on 12/08/23.
//

#include "intervalOverlap.h"
#include "vector"
#include "iostream"
#include <string>
#include <sstream>
using namespace std;

class Point {
public:
    int t;
    bool isStart;

    Point(int t, bool isStart) : t(t), isStart(isStart) {};
};

struct cmp {
    bool operator()(const Point *x, const Point *y) const {
        if(x->t== y->t){
            if(x->isStart == y->isStart){
                return 0;
            }else{
                return x->isStart ?-1:1;
            }
            return x->t>y->t?1:-1;
        }
    }
} myobj;

class Solution {
public:
    int convertTolong(string s) {
        char del = ':';
        vector<int> time;
        stringstream ss(s);
        string word1, word2;

        int i = 0;
        while (!ss.eof()) {
            if (i == 0) {
                getline(ss, word1, del);
                i++;
            } else {
                getline(ss, word2, del);
            }
        }
        int first = stoi(word1) * 60;
        int second = stoi(word2);
        int ans = first + second;
        cout<<ans<<endl;
        return ans;
    }

    bool haveConflict(vector<string> &event1, vector<string> &event2) {
        vector<Point *> points;
        int startPoint = convertTolong(event1[0]);
        int endPoint = convertTolong(event1[1]);

        Point *p = new Point(startPoint, true);
        Point *q = new Point(endPoint, false);
        points.push_back(p);
        points.push_back(q);

        startPoint = convertTolong(event2[0]);
        endPoint = convertTolong(event2[1]);

        p = new Point(startPoint, true);
        q = new Point(endPoint, false);
        points.push_back(p);
        points.push_back(q);

        std::sort(points.begin(), points.end(), myobj);
        int counter = 0;
        bool result = false;
        for (auto x: points) {
            if (x->isStart) {
                counter++;
                if (counter > 1) {
                    result = true;
                    break;
                }
            } else {
                counter--;
            }
        }
        return result;
    };
};

int main() {
    vector<string> e1={"01:15", "02:00"};
    vector<string> e2={"02:00", "03:00"};
    Solution s;
    cout << s.haveConflict(e1, e2);

}
