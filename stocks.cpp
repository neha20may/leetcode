//
// Created by neha2 on 04-02-2022.
//

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> p_diff(prices.size());
        adjacent_difference(prices.begin(), prices.end(), p_diff.begin());
        vector<int>x(p_diff.size()-1);
        x[0]=p_diff[1];
        for(int i=2;i<p_diff.size(); i++){
            x[i-1]=max(p_diff[i], p_diff[i]+x[i-2]);
        }
        return *max_element(x.begin(), x.end());
    }
};

int main(){
    vector<int> test={1};
    Solution s;
    cout<<" profit"<< s.maxProfit(test)<<endl;
}