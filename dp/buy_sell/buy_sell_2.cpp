//
// Created by neha2 on 14-04-2022.
//
#include <bits/stdc++.h>
#include "reader.h"

using namespace std;

class Solution {
    enum options {
        buy, sell, skip
    };

public:
    vector<vector<int>> mem;
    vector<vector<int>> dp;

/**
 * Final approach: idea borrowed from 0/1 knapsack top-down DP!
 * @param input
 * @param current_index
 * @param bought
 * @return
 */
    int recursion(vector<int> &input, int current_index, bool bought) {
        if (current_index >= input.size()) {
            return 0;
        }
        if (dp[bought][current_index] != -1) {
            return dp[bought][current_index];
        }
        int profit = 0;
        int profit1 = 0, profit2 = 0;
        int profit3 = recursion(input, current_index + 1, bought);
        if (bought) {
            //sell
            profit1 = input[current_index] + recursion(input, current_index + 1, false);
        } else {
            //buy
            profit2 = -input[current_index] + recursion(input, current_index + 1, true);
        }
        profit = max(profit3, max(profit1, profit2));
        dp[bought][current_index] = profit;
        return dp[bought][current_index];
    }

    /**
     * Not all test cases passes in this approach
     * @param input
     * @param temp_op
     * @param day_number
     * @param bought
     * @param n
     * @param final_ans
     */
    void fun(vector<int> input, int temp_op, int day_number, bool bought,
             int n, int &final_ans) {
        if (day_number > n - 1) {
            if (mem[bought][day_number] != -1) {
                final_ans = mem[bought][day_number];
            } else {
                final_ans = max(final_ans, temp_op);
                mem[bought][day_number] = final_ans;
            }
            return;
        }
        if (mem[bought][day_number] != -1) {
            return;
        } else {
            int op3 = temp_op;
            fun(input, op3, day_number + 1, bought, n, final_ans);
            if (!bought) {
                int op2 = temp_op - input[day_number];
                fun(input, op2, day_number + 1, true, n, final_ans);

            } else {
                int op1 = temp_op + input[day_number];
                fun(input, op1, day_number + 1, false, n, final_ans);
            }
        }
    }

    int maxProfit1(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;
        int profit = 0;
        int n = prices.size();
        for (int i = 0; i < n - 2; i++) {
            if (prices[i + 1] > prices[i]) {
                profit += prices[i + 1] - prices[i];
            }
        }
        if (prices[n - 1] > prices[n - 2]) {
            profit += prices[n - 1] - prices[n - 2];
        }
        return profit;
    }

    int maxProfit(vector<int> &p) {
        vector<int> input = p;
        int n = p.size();
        int op = 0;
        int day_number = 0;
        int final_ans = 0;
        mem.resize(2, vector<int>(p.size() + 1, -1));
        dp.resize(2, vector<int>(p.size(), -1));
//        fun(input, op - input[0], day_number + 1, true, p.size(), final_ans);
//        fun(input, op, day_number + 1, false, p.size(), final_ans);
//        return max(mem[true][n], mem[false][n]);
        recursion(input, 0, false);
        int ans = dp[0][0];
        return ans;
    }
};


int main() {
    vector<int> p = read_input();
    Solution s;
    int profit = s.maxProfit(p);
    cout << "profit =" << profit << endl;

}