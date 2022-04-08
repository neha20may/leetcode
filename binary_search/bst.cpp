//
// Created by neha2 on 31-01-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        set<int> bst(nums.begin(), nums.end());
        auto it = bst.find(target);
        if (it != bst.end()) {
            int d = distance(bst.begin(), it);
            return d;
        } else {
            auto it = bst.insert(target);
            return distance(bst.begin(), it.first);
        }
    }
};

int main() {

}
