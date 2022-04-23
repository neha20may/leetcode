//
// Created by neha2 on 21-04-2022.
//

/*
This solution is for positive and negative numbers.
For inly non negative numbers, normal sliding window can be used.
https://www.geeksforgeeks.org/find-subarray-with-given-sum/

Another trick is change inout to only +ve numbers by adding min negative absolute numbers
*/
// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         unordered_map<int, int> psum;
//         psum.insert({0,1}); //case when sum==k and you search key(psum-k )
//         int sum=0;
//         int count=0;
//         for(int i=0; i<nums.size(); i++){
//             sum+=nums[i];
//             if(psum.find(sum-k)!=psum.end()){
//                 count+=psum[sum-k];
//             }
//             psum[sum]++;
//         }
//         return count;
//     }
// };
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int minEle = INT_MAX;
        int n = nums.size();
        vector<int> &arr = nums;
        int count = 0;
        // Find minimum element in the array
        for (int i = 0; i < n; i++) {
            minEle = min(arr[i], minEle);

            // Initialize curr_sum as value of first element
            // and starting point as 0
            int curr_sum = arr[0] + abs(minEle), start = 0, i;

            // Starting window length will be 1,
            // For generating new target sum,
            // add abs(minEle) to sum only 1 time
            int targetSum = k;

            // Add elements one by one to curr_sum
            // and if the curr_sum exceeds the
            // updated sum, then remove starting element
            for (i = 1; i <= n; i++) {

                // If curr_sum exceeds the sum,
                // then remove the starting elements
                while (curr_sum - (i - start) * abs(minEle) > targetSum && start < i) {
                    curr_sum = curr_sum - arr[start] - abs(minEle);
                    start++;
                }

                // If curr_sum becomes equal to sum, then return true
                if (curr_sum - (i - start) * abs(minEle) == targetSum) {
                    cout << "Sum found between indexes " << start << " and " << i - 1;
                    count++;

                }

                // Add this element to curr_sum
                if (i < n) {
                    curr_sum = curr_sum + arr[i] + abs(minEle);
                }
            }

            // If we reach here, then no subarray
            cout << "No subarray found";
        }
    }
};