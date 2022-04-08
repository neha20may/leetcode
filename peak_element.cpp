//
// Created by neha2 on 27-02-2022.
//

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int getPeak(vector<int> &nums, int i, int j){
        if(i>=j)
            return i;
        int mid=(i+j)/2;
        int mid_left=0, mid_right=0;
        if(mid==0)
        {
            mid_left=INT_MIN;
        }
        else{
            mid_left=nums[mid-1];
        }
        if(mid==nums.size()-1){
            mid_right=INT_MIN;
        }
        else{
            mid_right=nums[mid+1];
        }
        cout<<mid_left<<" :: "<<mid_right<<endl;
        if(mid_left<nums[mid] && mid_right<nums[mid]){
            return mid;
        }else{
            if(mid_left<nums[mid] && mid_right>nums[mid]){
                i=mid+1;
                return getPeak(nums, i, j);

            }
            else if(mid_left>nums[mid] && mid_right<nums[mid]){
                j=mid-1;
                return getPeak(nums, i,j);

            }else{
                i=mid+1;
                return getPeak(nums, i, j);
            }
        }

    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return  0;
        int peak=0;
        int left =0;
        int right=nums.size()-1;

        return getPeak(nums, left, right);

    }
};

int main() {
    vector<int> v = {6,5,4,3,2,3,2};
    Solution s;
    int i=s.findPeakElement(v);
    cout<<"peak is "<<v[i]<<endl;
}