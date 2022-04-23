//
// Created by neha2 on 15-04-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> mem;
    bool solve(string &s, string &p, int i, int j) {
        if(mem[i][j]!=-1)
            return mem[i][j];
        bool ans = false;
        if (i >= s.length() && j >= p.length()) {
            return true; //check
        }
        if (j >= p.size()) {
            return false; //this condition I didnt write!
        }
/**
 *  0 0 both are in bounds -> go to fun body
 *  0 1 string is in bound pattern out of bound ; return  false; example: "aaa" "a*" -> this does not get out of bounds for pattern as it checks the piche wala for *.
 *  1 0 string out of bounds pattern in bound; check in fun body example: "a" "ab*"
 *  1 1 both are out of bounds, both processed; return true;
 */
        bool cond= (i<s.size() && (s[i] == p[j] || p[j] == '.')); //This condition is very critical here
        // i< s.size() should be checked before the rest of it, parenthesis are important.
        if (j + 1 < p.size() && p[j + 1] == '*') {
            //empty
            bool ans1 = solve(s, p, i, j + 2);
            //replace with previous character
            bool ans2=false;
            if(cond){
                ans2=solve(s, p, i + 1, j);
            }
            ans = (ans1 or ans2);
            mem[i][j]=ans;
            return ans;
        }
        if (cond) {
            mem[i][j]=solve(s, p, i + 1, j + 1); //I forgot to return here!
            return mem[i][j];
        } else {
            mem[i][j]=false;
            return false;
        }
    };

    bool isMatch(string s, string p) {
        if (s.length() == 1)
            if (p.length() == 1) {
                if (s[0] == p[0] || p[0] == '.')
                    return true;
                else
                    return false;
            }
        mem.resize(s.size()+1,vector<int>(p.size()+1,-1));
        bool ans = solve(s, p, 0, 0);
        return ans;
    }
};

int main() {
    //"bbbba"
    //".*a*a"
    string ss = "bbbba";
    string p = ".*a*a*";
    Solution s;
    cout << s.isMatch(ss, p);
}