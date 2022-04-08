//
// Created by neha2 on 06-03-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void fill(string s, int i, int j, vector<vector<bool>> &dp){
        if(i==j)
            return;
        if(i+1==j)
            return;
        if(s[i]==s[j]){
            fill(s, i+1, j-1, dp);
            dp[i][j]=dp[i+1][j-1];
        }else{
//            fill(s, i+1, j, dp);
//            fill(s, i, j-1, dp);
            dp[i][j]= false;
        }
    }
    string longestPalindrome(string s) {
        if(s.length()<=1)
            return s;
        int n=s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        for(int i=0;i<n-1;i++)
            dp[i][i+1]=(s[i]==s[i+1])?true:false;
        fill(s, 0, n-1, dp);
        string p="";
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                if(dp[i][j]==true){
                    if(p.length()<=s.substr(i,j-i+1).length()){
                        p=s.substr(i, j-i+1);
                    }
                }
            }
        return p;
    }
};

int main() {
    string a = "geeksskeegabcgngncfgn";
    Solution s;
    cout << s.longestPalindrome(a);
}