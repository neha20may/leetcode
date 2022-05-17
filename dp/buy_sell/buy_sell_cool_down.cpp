//
// Created by neha2 on 15-04-2022.
//
#include <bits/stdc++.h>
#include "reader.h"
using namespace std;
class Solution {
    vector<vector<int>> dp;
public:
    int recursion(vector<int> &input, int current_index, bool bought){
        if(current_index >=input.size() ){
            return 0;
        }
        if(dp[bought][current_index]!=-1)
            return dp[bought][current_index];
        int profit=0;
        int profit3=recursion(input, current_index+1, bought);
        int profit1=0, profit2=0;
        if(bought){
            //sell
            profit1=input[current_index]+recursion(input, current_index+2, !bought);
        }else{
            //buy
            profit2=-input[current_index]+recursion(input, current_index+1, !bought);
        }
        profit=max(profit3, max(profit1, profit2));
        dp[bought][current_index]=profit;
        return dp[bought][current_index];

    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1)
            return 0;
        dp=vector<vector<int>>(2, vector<int>(prices.size(), -1));
        recursion(prices, 0, false);
        return dp[0][0];
    }
};
int main() {
    vector<int> p = read_input();
    Solution s;
    int profit = s.maxProfit(p);
    cout << "profit =" << profit << endl;

}