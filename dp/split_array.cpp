//
// Created by neha2 on 18-04-2022.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<vector<int>>> mem;
    int sum(int s, int e, vector<int> &nums){
        // cout<<"sum b/e start="<<s<<" end= "<<e<<endl;
        int sum=0;
        for(int i=s; i<=e; i++){
            sum+=nums[i];
        }
        return sum;
    }
    int solve(vector<int> &nums, int sindex, int eindex, int m){
        // cout<<"s index="<<sindex<<"eindex="<<eindex<<endl;
        if(mem[m][sindex][eindex]!=-1){
            return mem[m][sindex][eindex];
        }
        if(m==1){
            // cout<<"check"<<endl;

            mem[1][sindex][eindex]=sum(sindex, eindex, nums);
            return mem[m][sindex][eindex];
        }
        int ans=INT_MAX;
        for(int end=sindex; end<nums.size(); end++){
            int sf=solve(nums, sindex, end, 1);
            int ss=solve(nums, end+1, eindex, m-1);
            // cout<<" sum between sindex="<<sindex<<" and end="<<end<<" ";
            // cout<<"="<<sf<<"; for end+1 ="<<end+1<<" to eindex="<<eindex<<" = "<<ss<<endl;
            int msum= max(sf,ss );
            ans=min(ans, msum);
            msum=0;
        }
        mem[m][sindex][eindex]=ans;
        return mem[m][sindex][eindex];
    }
    int sum(vector<int> &nums){
        int sum=0;
        for(auto x: nums){
            sum+=x;
        }
        return sum;
    }
    int splitArray(vector<int>& nums, int m) {
        if(m==1)
            return sum(nums);
        mem.resize(m+1, vector<vector<int>>(nums.size()+1,vector<int>(nums.size()+1, -1)));
        solve(nums, 0, nums.size()-1, m);
        return mem[m][0][nums.size()-1];

    }
};
int main(){
    Solution sl;
    vector<int> v={7,2,5,10,8};
    sl.splitArray(v, 2);
}
