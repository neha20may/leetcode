//
// Created by neha2 on 03-03-2022.
//
#include <bits/stdc++.h>
using namespace  std;
class Solution {
public:
    int getSum(int a, int b) {
        if(b==0)
            return a;
        int s=a^b;
        int c=(a&b)<<1;
        /**
         * why this is a carry?
         * Bcz carry will come only at the positions where both bits are 1. hence &, and they will be added to next bit; hence in next call, you add, s and c.
         * you do that till your caryy is null.
         */
        return getSum(s,c);
    }
};

int main(){
    int a=-1;
    int b=1;
    Solution s;
    cout<<s.getSum(a,b);
}