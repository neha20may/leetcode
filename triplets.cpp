//
// Created by neha2 on 05-02-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void searchPair(vector<int>&nums, int target, int left, vector<vector<int>>&triplets){
        int right=nums.size()-1;
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum==target){
                triplets.push_back({-target, nums[left], nums[right]});
                left++;
                right--;
            }
            if(sum>target)
            {
                right--;
            }
            if(sum<target)
            {
                left++;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>triplets;
        sort(nums.begin(), nums.end());
        if(nums.size()>2)
            for(int i=0;i<nums.size()-2;i++){
                searchPair(nums, -nums[i], i+1, triplets);
            }
        return triplets;

    }
};

int main() {
    vector<int> nums = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    Solution s;
    auto t = s.threeSum(nums);
    auto ui=unique(t.begin(), t.end());
    t.resize(distance(t.begin(), ui));
    for (auto x: t) {
        for (auto y: x)
            cout << y << " ";
        cout << endl;
    }
}