//
// Created by neha2 on 15-04-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool ans;

    bool isValid(string s) {
        // cout << "checking string s for validitiy =" << s << endl;
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                st.push(c);
            }
            if (c == ')') {
                if (st.empty())
                    return false;
                else {
                    if (st.top() == '(')
                        st.pop();
                    else
                        return false;
                }
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    };

    vector<int> mem;
    bool dfs(int i, string l, string &s) {
//        cout << "dfs call s=" << s << " i =" << i << endl;
        // if(mem[i]!=-1)
             return mem[i];
        if (i >= s.length()) {
            if (isValid(s)) {
                ans=true;
                return true;
            }
            return false;
        }
        bool a1, a2,a=false;
        if(!ans){
            if (l[i] == '0') {
                char c = s[i];
                char o = c;
                if (c == '(')
                    c = ')';
                else
                    c = '(';
                s[i] = c;
                a1=dfs(i + 1, l, s);
                s[i] = o;
            }
            a2=dfs(i + 1, l, s);
            a= a1||a2;
            mem[i]=a;
            return a;
        }
        else
            return true;

    }

    bool canBeValid(string s, string locked) {
        if (s.size() == 1) {
            return false;
        }
        if(isValid(s))
            return true;
        if(locked[0]==1 && s[0]==')')
            return false;
        if(locked[s.size()-1]==1 && s[s.size()-1]=='(')
            return false;

        mem.resize(s.size()+1, -1);
        bool ans=dfs(0, locked, s);
        return ans;
    }
};

int main() {
    //"))()))"
    //"010100"


    string s = "())(()(()(())()())(())((())(()())((())))))(((((((())(()))))(";
    string locked = "100011110110011011010111100111011101111110000101001101001111";
    Solution sl;
    cout<<sl.canBeValid(s, locked);
}