//
// Created by neha2 on 23-02-2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(vector<int> nums, int i, vector<int> op,
               vector<vector<int>> &ans) {
        unordered_map<int, int >m;

        if (nums.size() == 0) {
            ans.push_back(op);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            vector<int> partial_op = op;
            partial_op.push_back(n);
            nums.erase(nums.begin() + i);
            solve(nums, i + 1, partial_op, ans);
            nums.emplace(nums.begin() + i, n);
        }

    }

    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.size() == 0)
            return vector<vector<int>>();
        else {
            vector<vector<int>> ans;
            vector<int> op;
            int i = 0;
            solve(nums, i, op, ans);
            return ans;
        }

    }
};

int main() {
    vector<int> i = {1, 2, 3};
    Solution s;
    s.permute(i);
}

