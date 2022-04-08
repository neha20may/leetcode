//
// Created by neha2 on 20-02-2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(int open, int close, string op, vector<string> &ans) {
        if (close == 0 && open == 0) {
            ans.push_back(op);
            return;
        }
        string oB = op + "(";
        string cB = op + ")";
        if (close > open) {
            solve(open, close - 1, cB, ans);
        }
        if (open != 0) {
            solve(open - 1, close, oB, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return vector<string>();
        else {
            string op = "(";
            int open = n - 1, close = n;
            vector<string> ans;
            solve(open, close, op, ans);
            return ans;
        }
    }
};

class SolutionA {
    vector<string> ans;
    void rec(string s, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        if (open > 0) {
            s.push_back('(');
            rec(s, open - 1, close);
            s.pop_back();
        }
        if (close > 0 && open < close) {
            s.push_back(')');
            rec(s, open, close - 1);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        rec("", n, n);
        return ans;
    }
};

int main() {
    int n = 3;
    Solution s;
    vector<string> ans, ansA;
    ans=s.generateParenthesis(n);
    SolutionA sa;
    ansA=sa.generateParenthesis(n);
    cout<<"";
}
