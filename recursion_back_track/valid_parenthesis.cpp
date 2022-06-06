/**
https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/
*/
#include <bits/stdc++.h>
using namespace  std;
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;
        for(int i=0; i<s.size(); i++){
            char c=s[i];
            if(c=='(')
                open.push(i);
            if(c=='*')
                star.push(i);
            if(c==')'){
                if(!open.empty())
                    open.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;

            }
        }
        if(!open.empty() && !star.empty()){
            while(!open.empty() && !star.empty()){
                int oi=open.top();
                int stari=star.top(); //this piece is critical, matching stars against open brackets.
                if(stari>oi){
                    star.pop();
                    open.pop();
                }else{
                    return false;
                }
            }
        }
        if(open.empty() && !star.empty()){
            // int count=star.size();
            // if(count%2==0)
            //     return true;
            // else
            //     return false;
            //stars can be treated as empty spaces here.
            return true;
        }
        if(open.empty() && star.empty()){
            return true;
        }

        return false;
    }
};
int main(){
    Solution s;
    string s1="((((*)))";
    cout<<s.checkValidString(s1)<<endl;
    return 0;
}