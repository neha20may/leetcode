//
// Created by neha2 on 02-04-2022.
//
#include <bits/stdc++.h>
using namespace  std;
class Solution {
public:
    int getRemovalCount(string s){
        stack<char> st;
        for(auto c: s){
            if(c=='(')
                st.push(c);
            else{
                if(c==')'){
                    if(st.size()==0)
                        st.push(c);
                    else if(st.top()=='(')
                        st.pop();
                    else if(st.top()==')')
                        st.push(c);
                }
            }
        }
        return st.size();
    }
    void remove(string s, int min, unordered_set<string> &ans, int leftC, int rightC){
        // cout<<"remove s inout "<<s<<endl;
        if(min==0){
            if(getRemovalCount(s)==0){
                ans.insert(s);
                return;
            }
            return;
        }
        int n=s.size();
        for(int i=0;i<n; i++){
            if(s[i]=='(')
                leftC--;
            if(s[i]==')')
                rightC--;
            // cout<<"i "<<i<<" char at i "<<s[i]<<endl;
            if(s[i]!='(' and s[i]!=')')
                continue;
            //aplly rule: check if right_count < left_count. If this is the case then only we consider that right parenthesis and recurse further.
            string left=s.substr(0, i);
            string right=s.substr(i+1);
            if(s[i]==')' and right<left)
                remove(left+right, min-1, ans, leftC, rightC);
            else
                if(s[i]=='(')
                    remove(left+right, min-1, ans, leftC, rightC);
        }
    }
    int getleft(string s){
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                count++;
        }
        return count;
    }
    int getright(string s){
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==')')
                count++;
        }
        return count;
    }
    vector<string> removeInvalidParentheses(string s) {
        if(s.length()==1){
            if(s==")" or s=="(")
                return vector<string>(1,"");
            else
                return vector<string>(1,s);
        }
        int mr=getRemovalCount(s);
        int left=getleft(s);
        int right=getright(s);
        // cout<<"mr "<<mr<<endl;
        unordered_set<string> ans;
        remove(s, mr, ans, left, right);
        return vector<string>(ans.begin(), ans.end());
    }
};
int main(){
    string s = "()())()";
    Solution a;
    vector<string> ans=a.removeInvalidParentheses(s);
    for(auto s: ans)
    cout<<s<<" ";
}