//
// Created by neha2 on 17-06-2022.
//

/**
coin change 1 : https://leetcode.com/problems/coin-change/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int i, int amount, vector<int> &coins) {
        cout << i << " " << amount << endl;
        if (i >= coins.size())
            return 0;

        if (amount == 0)
            return 1;

        int ans1 = 0, ans2 = 0;
        if (coins[i] <= amount) {
            ans1 = solve(i, amount - coins[i], coins);
            cout << "ans1 " << ans1 << endl;
        }
        ans2 = solve(i + 1, amount, coins);
        cout << "ans2 " << ans2 <<
             endl;
        int ans = ans1 + ans2;
        return
                ans;
    }

    int change(int amount, vector<int> &coins) {
        int ans = solve(0, amount, coins);
        return ans;
    }

};

int main() {
    vector<int> coins = {1, 2, 5};
    Solution solution;
    int ans = solution.change(5, coins);
    cout << ans << endl;
}