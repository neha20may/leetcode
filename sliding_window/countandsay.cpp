//
// Created by neha2 on 07-03-2022.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getNo(vector<string> &v, int i){
        string n=v[i-1];
        // cout<<"prev "<<n<<endl;
        unordered_map<int, int> m;
        vector<int> digits;
        for (char d: n){
            int digit=d-'0';
            digits.push_back(digit);
        }
        // copy(digits.begin(), digits.end(), ostream_iterator<int>(cout," ")); cout<<endl;
        string ans="";
        int N=digits.size();
        int k=0;

        while(k<N-1){
            // cout<<"digit "<<digits[k]<<endl;
            m[digits[k]]++;
            if(digits[k]==digits[k+1]){

                // cout<<"md"<<m[digits[k]]<<endl;
                k++;
                continue;
            }
            else{
                string s=to_string(m[digits[k]])+to_string(digits[k]);
                // cout<<"s "<<s<<endl;
                ans+=s;
                m.erase(digits[k]);
            }
            k++;
            // cout<<"inner loop map"<<endl;
            // for(auto p:m){
            //         cout<<p.first<<" "<<p.second<<endl;
            // }
        }
        m[digits[k]]++;
        // cout<<"outer map"<<endl;
        // for(auto p:m){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        string s=to_string(m[digits[k]])+to_string(digits[k]);
        ans+=s;
        // cout<<"answer "<<ans<<endl;
        return ans;

    }
    string countAndSay(int n) {
        vector<string> v(n+1,"#");
        v[1]="1";
        v[2]="11";
        for(int i=3; i<=n;i++){
            v[i]=getNo(v,i);
        }
        return v[n];
    }
};
