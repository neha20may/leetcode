//
// Created by neha2 on 06-03-2022.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
    string create_vector(string &s){
        int n=s.size();
        vector<int> v(26,0);
        for(auto c:s){
            int index=c-'a';
            v[index]++;
        }
        string vs=string("");
        for(auto i:v){
            vs=vs+"#"+to_string(i);
        }
        return vs;
    }
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, list<string>> m;
        for(auto i=strs.begin();i!=strs.end(); i++){
            string s=*i;
            string v=create_vector(s);
            cout<<"string vector i s "<<v <<endl;
            if(m.find(v)!=m.end()){
                m[v].push_back(s);
            }else
            {
                m[v]=list<string>(1,s);
            }
        }
        //TODO: Revise it
        /**
         * Good question to understand the knowledge gaps!
         */
        vector<vector<string>> result;
        for(auto p:m){
            auto l=p.second;
            vector<string> temp;
            /**
             * if temp is decalared without allocating memory ; vector<string>temp;
             * then ,
             * copy(....... temp.begin()) gives segmentaion faut;
             * to avoid allocating unnecessary memory, dealre the temp vector<string>temp and then use
             * copy(....... back_inserter(temp));
             * segmentation fault in vector is mostly not allocating memory and then trying to access the memory.
             */
            copy(l.begin(), l.end(), back_inserter(temp));
            result.push_back(temp);
            temp.clear();
        }
        return result;

    }
};
int main(){
//    vector<string> v({"eat","tea","tan","ate","nat","bat"});
    vector<string> v({"bdddddddddd","bbbbbbbbbbc"});
    Solution s;
    s.groupAnagrams(v);
}
