//
// Created by neha2 on 13-06-2022.
//
#include <bits/stdc++.h>
using namespace  std;

class Solution {
public:
    int solve(int i1, int i2, vector<int>& nums1, vector<int>& nums2, int n1, int n2, int partial_ans){
        // cout<<"index "<<i1<<" "<<i2<<endl;
        // cout<<partial_ans<<endl;
        if(i1==n1 || i2==n2){
            //?ans?
            return partial_ans;
        }

//         if(i1>=n1){
//             //?
//             return 0;
//         }
//         if(i2>=n2){
//             ///?
//             return 0;
//         }
        int a1=partial_ans, a2=0, a3=0;
        if(nums1[i1]==nums2[i2]){
            a1=solve(i1+1, i2+1, nums1, nums2, n1, n2, partial_ans+1);
        }

            a2=solve(i1, i2+1, nums1, nums2, n1, n2, 0);  //notice the partial op is reset if the ca=harcters dont match
            a3=solve(i1+1, i2, nums1, nums2, n1, n2, 0);



        int ans=max(a1, max(a2, a3));
        return ans;

    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
       int ans=solve(0, 0, nums1, nums2, nums1.size(), nums2.size(), 0);
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums1={1,1,0,0,1};
    vector<int> nums2={1,1,0,0,0};
    cout<<s.findLength(nums1, nums2)<<endl;
    return 0;
}