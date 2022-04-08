//
// Created by neha2 on 08-03-2022.
//
#include <bits/stdc++.h>
using namespace  std;
class Solution {
public:
    void print(vector<int> &dp){
        for(auto i:dp)
            cout<<i<<" ";
        cout<<endl;
    }
    void jump(vector<int>& nums ,  vector<int> &dp, int index){
        // cout<<"current index "<<index<<endl;
        if(index==nums.size()-1)
        {   dp[index]=1;
            // print(dp);
            return;
        }
        if(dp[index]!=-1){
            return;
        }
        int steps=nums[index];
        int step=1;
        for(;step<=steps;step++){
            // cout<<"step "<<step<<endl;
            // print(dp);
            int next_index=index+step;
            // cout<<"next index "<<next_index<<endl;
            if(next_index<=nums.size()-1){
                jump(nums, dp, next_index);
                if(dp[next_index]==1){
                    dp[index]=1;
                    break;
                }
            }
        }
        // cout<<"after all steps "<<endl;
        // print(dp);
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);
        jump(nums, dp, 0);
        bool ans=(dp[0]==1)?true:false;
        return ans;
    }
};
class Solution2 {
public:
    bool can_reach(int i, int j, vector<int>&nums){
        int steps=nums[i];
        if(steps==0)
            return false;
        else{
            for(int k=1; k<=steps; k++){
                int ni=i+k;
                if(ni==j)
                    return true;
            }
            return false;
        }

    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n, false);
        dp[n-1]=true;
        for(int i=n-2; i>=0;i--){
            int j=i+1;
            for(; j<n;j++){
                if((dp[j]==true) and (can_reach(i, j, nums))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};

int main(){
    vector<int> test={2,1,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    Solution2 s;
    cout<<s.canJump(test)<<endl;
}
