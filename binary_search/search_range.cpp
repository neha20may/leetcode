//
// Created by neha2 on 27-02-2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void binary_search(vector<int>::iterator left,
                       vector<int>::iterator right, int target,
                       vector<int>::iterator &pos) {
        if (left>= right)
            return;
        vector<int>::iterator mid = left + (right - left) / 2;
        if (*mid == target) {
            pos = mid;
            return;
        } else if (*mid < target) {
            return binary_search(mid+1, right, target, pos);
        } else {
            return binary_search(left, mid, target, pos);
        }

    }

    vector<int>::iterator search_left(vector<int>::iterator left,
                                      vector<int>::iterator right, int target) {
        vector<int>::iterator pos_input = right, pos = right;
        binary_search(left, right, target, pos);
        if (pos != right)
            return search_left(left, pos, target);
        else
            return pos;
    }

    vector<int>::iterator search_right(vector<int>::iterator left,
                                       vector<int>::iterator right, int target) {
        vector<int>::iterator pos_input = left, pos = left;
        binary_search(left, right, target, pos);
        if (pos != left)
            return search_right(pos, right, target);
        else
            return pos;
    }


    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.size() == 0)
            return vector<int>();
        if (nums.size() == 1)
            if (target == nums[0])
                return vector<int>({0, 0});
            else
                return vector<int>();
        // >=2 elemnts in nums
        vector<int>::iterator i = nums.end();
        binary_search(nums.begin(), nums.end(), target, i);
        if (i == nums.end())
            return vector<int>();
        vector<int> range;
        //search for left range
        vector<int>::iterator l = search_left(nums.begin(), i, target);
        //search for right range
        vector<int>::iterator r = search_right(i, nums.end(), target);
        range.push_back(distance(nums.begin(), l));
        range.push_back(distance(nums.begin(), r));
        return range;

    }
};

int main() {
    vector<int> v = {1,1,2,3,4};
    Solution solution;
    vector<int> r=solution.searchRange(v,1);
    for(auto x:r)
        cout<<x<<" ";
}