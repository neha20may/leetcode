//
// Created by neha2 on 06-02-2022.
//
#include <bits/stdc++.h>
using  namespace  std;
class Solution {
public:
    int find_pivot(vector<int>&nums){
        int left=0;
        int right=nums.size()-1;
        if(right==left){
            //one element
            return left;
        }else if(left+1==right){
            //two elements
            if(nums[0]>nums[1]){
                return 1;
            }
            else
                return 0;
        }
        else{
            //size should be atleaast 3 here
            int left=0;
            int right=nums.size()-1;

            while(left<right){
                int mid=left+(right-left)/2;
                if(nums[mid]>nums[right]){
                    left=mid+1;
                }
                else{
                    right=mid;
                }
            }
            return left;

        }

    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        else if(nums.size()==1){
            if (target==nums[0])
                return 0;
            else
                return -1;
        }
        int start=find_pivot(nums);
        set<int> first(nums.begin()+start, nums.end());
        set<int> second(nums.begin(), nums.begin()+start);
        auto fi=first.find(target);
        auto si=second.find(target);
        if(fi!=first.end())
            return start+distance(first.begin(),fi);
        else
            return distance(second.begin(), si);


    }
};
int main(){
    vector<int> x={3,1};
    int target=1;
    Solution s;
    int index=s.search(x, target);
    cout<<index<<endl;
}
