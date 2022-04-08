//
// Created by neha2 on 06-02-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int get_minimumm_coins(vector<int> &coins, int amount, vector<int> &dp_table) {
        auto coin = coins.begin();
        while (coin != coins.end()) {
            if (*coin <= amount) {
                int coins_i = 1 + dp_table[amount - *coin];
                dp_table[amount] = min(dp_table[amount], coins_i);
            }
            coin++;
        }

        return dp_table[amount];

    }

    int coinChange(vector<int> &coins, int amount) {
        // int n=amount.size();
        vector<int> ans(amount + 1, amount + 1);
        ans[0] = 0;
        for (int a = 1; a <= amount; a++) {
            int min_coins = get_minimumm_coins(coins, a, ans);
            cout << " amount " << a << " min coins " << min_coins << endl;
        }
        return ans[amount] > amount ? -1 : ans[amount];
    }
};

int main() {
    vector<int> coins = {2};
    int amount = 3;
    Solution s;
    cout << s.coinChange(coins, amount) << endl;
}
