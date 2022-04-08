//
// Created by neha2 on 03-04-2022.
//
#include <bits/stdc++.h>
using  namespace std;
class Solution {
    struct pair_hash{
        size_t operator()(const pair<string, string> & p)const{
            auto h1=std::hash<string>{}(p.first);
            auto h2=std::hash<string>{}(p.second);
            return h1^h2;
        }
    };
public:
    // vector<vector<int>> memo; ===> gives TLE
    unordered_map<pair<string, string>, bool, pair_hash> memo;
    bool allstar(string p){
        for(char c:p)
            if(c!='*')
                return false;
        return true;
    }
    int call(string s, string p, int i, int j, int m, int n){
        // cout<<"s = "<<s<<"; p = "<<p<<"; i = "<<i<<"; j = "<<j<<endl;
        if(i!=m and j==n)
        {
            memo[make_pair(s,p)]=false;
            return memo[make_pair(s,p)];
        }
        if(i==m and j==n)
        {
            memo[make_pair(s,p)]=true;
            return memo[make_pair(s,p)];
        }
        if(i==m and j!=n){
            if(allstar(p))
            {
                memo[make_pair(s,p)]=true;
                return memo[make_pair(s,p)];
            }
            else
            {
                memo[make_pair(s,p)]=false;
                return memo[make_pair(s,p)];
            }
        }
        if(i!=m and j!=n){
            if(memo.find(make_pair(s,p))==memo.end()){
                char xi=s[0], yj=p[0];
                // cout<<"xi "<<xi<<" yj "<<yj<<endl;
                if(yj!='*' and yj!='?'){
                    if(yj!=xi)
                    {
                        memo[make_pair(s,p)]=false;
                        return memo[make_pair(s,p)];
                    }
                    else
                    {
                        memo[make_pair(s,p)]= call(s.substr(1), p.substr(1), i+1, j+1, m, n);
                        return  memo[make_pair(s,p)];
                    }
                }
                if(yj=='?'){
                    memo[make_pair(s,p)]=call(s.substr(1), p.substr(1), i+1, j+1, m, n);
                    return  memo[make_pair(s,p)];
                }
                if(yj=='*'){
                    // cout<<"caling for ans1"<<endl;
                    bool ans1=call(s.substr(0), p.substr(1), i, j+1, m, n);
                    // cout<<"ans 1 = "<<ans1<<endl;
                    // cout<<"caling for ans 2"<<endl;
                    bool ans2=call(s.substr(1), p.substr(0), i+1, j, m, n);
                    // cout<<"ans 2 = "<<ans2<<endl;
                    memo[make_pair(s,p)]=(ans1 or ans2);
                    return  memo[make_pair(s,p)];
                }
            }
            else
                return memo[make_pair(s,p)];
        }
        return 0;
    }
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        memo=unordered_map<pair<string, string>, bool, pair_hash>(3000);
        call(s,p, 0, 0, m, n);
        int ans=memo[make_pair(s,p)];
        if(ans==1)
            return true;
        else
            return false;
    }
};

int main(){
    string s="bbbbbbbabaabaaabaaaaaabbbabbabbaaabbbabaabbababbabaaabbbbaaabbabbbaabbabbabaaaaaaaaabbbabbabaaabbbbaabbbbaabbabbabbbaabababbabaaababaaaaaabbabaaabbbbbbababbbbbaaabbabbaaaaababaaabbbaaaababbbbbbaababaaa";
    string  p="**b*bb*aa*baaaa*aaa*b*baaa*a*aaa*b*a*ba**ba*ba*ba*b*b****a*ba*b**a*****ba*bb*a***abb***a*bb***b**abb*";
    Solution sl;
    cout<<sl.isMatch(s, p);
}