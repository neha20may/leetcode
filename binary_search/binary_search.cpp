//
// Created by neha2 on 05-02-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void search(vector<int> &nums, int target, int left, int right, vector<int> &ans) {
        if (right <= left) {
            if (nums[right] == target) {
                ans.push_back(left);
                ans.push_back(right);
                return;
            } else {
                ans.push_back(-1);
                ans.push_back(-1);
                return;
            }
        }
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            int midleft = mid, midright = mid;
            while (midleft >= left) {
                if (nums[midleft] == target)
                    midleft--;
                else break;
            }
            while (midright <= right) {
                if (nums[midright] == target)
                    midright++;
                else break;
            }
            ans.push_back(++midleft);
            ans.push_back(--midright);
        } else if (target < nums[mid]) {
            search(nums, target, left, mid, ans);
        } else if (target > nums[mid]) {
            search(nums, target, mid + 1, right, ans);
        }
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ans;
        if (nums.size() == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            int midleft = mid, midright = mid;
            while (midleft >= left) {
                if (nums[midleft] == target)
                    midleft--;
                else break;
            }
            while (midright <= right) {
                if (nums[midright] == target)
                    midright++;
                else break;
            }
            ans.push_back(++midleft);
            ans.push_back(--midright);
        } else if (target < nums[mid]) {
            search(nums, target, left, mid, ans);
        } else if (target > nums[mid]) {
            search(nums, target, mid + 1, right, ans);
        }
        if (ans.size() == 0) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};

int main() {
    vector<int> x = {1, 4};
    int i = 4;
    Solution s;
    bool is_present=binary_search(x.begin(), x.end(), i);
    find(x.begin(), x.end(), i); //normal search O(n)
    set<int> st(x.begin(), x.end());
    st.find(i);
    auto ans = s.searchRange(x, i);
    for (auto x: ans)
        cout << x << " ";
}