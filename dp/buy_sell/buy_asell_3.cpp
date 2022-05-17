
#include <bits/stdc++.h>
#include "reader.h"
using namespace std;

class Solution {
    vector<vector<vector<int>>> dp;
public:
    int recursion(vector<int> &input, int current_index, bool bought, int k){
        if(current_index >=input.size() || k<=0 ){
            return 0;
        }
        if(dp[bought][k][current_index]!=-1)
            return dp[bought][k][current_index];
        int profit=0;
        int profit3=recursion(input, current_index+1, bought, k);
        int profit1=0, profit2=0;
        if(bought){
            profit1=input[current_index]+recursion(input, current_index+1, !bought, k-1);
        }else{
            profit2=-input[current_index]+recursion(input, current_index+1, !bought, k-1);
        }
        profit=max(profit3, max(profit1, profit2));
        dp[bought][k][current_index]=profit;
        return dp[bought][k][current_index];

    }
    int maxProfit(vector<int>& prices) {
        dp=vector<vector<vector<int>>>(2, vector<vector<int>>(5, vector<int>(prices.size(), -1)));
        recursion(prices, 0, false, 4);
        return dp[0][4][0];
    }
};
int main(){
    vector<int> p = read_input();
    Solution s;
    int profit = s.maxProfit(p);
    cout << "profit =" << profit << endl;
}