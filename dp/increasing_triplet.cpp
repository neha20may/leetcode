//
// Created by neha2 on 07-03-2022.
//
#include <bits/stdc++.h>
using namespace  std;
/**
 * Time limit exceeded for extrmely large input
 */
class Solution1 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        bool ans=false;
        int small_value=numeric_limits<int>::min();
        vector<int> X(n+1, small_value);
        X[n]=0;
        for(int i=n-1; i>=0; i--){
            int maxj=0;
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i])
                    maxj=max(maxj, X[j]);
            }
            // cout<<"max j found "<<maxj<<endl;
            X[i]=1+maxj;
            if(X[i]==3){
                ans=true;
                break;
            }
        }
        // copy(X.begin(), X.end(), ostream_iterator<int>(cout, " ")); cout<<endl;
        return ans;
    }
};
/**
 * Too much memory
 *
 */
class Solution2 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int large=numeric_limits<int>::max();
        vector<stack<int>> stacks(n, stack<int>());
        vector<int> topstack(n, large);
        for(auto c:nums){
            auto pos=lower_bound(topstack.begin(), topstack.end(), c);
            int index=distance(topstack.begin(), pos);
            stacks[index].push(c);
            topstack[index]=c;
            if(index>=2)
                return true;
        }
        int pile=0, pile_size=0;
        for(auto st:stacks){
            if(!st.empty()){
                pile++;
                if(pile>=3){
                    return true;
                }
            }
        }
        return false;
    }
};
/**
 * Invisible stacks !
 * finally accepted
 */
class Solution3 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int large=numeric_limits<int>::max();
        vector<int> topstack(n, large);
        for(auto c:nums){
            auto pos=lower_bound(topstack.begin(), topstack.end(), c);
            int index=distance(topstack.begin(), pos);
            if(index>=2){
                return true;
            }

            topstack[index]=c;
        }

        return false;
    }
};

int main(){
    vector<int> test={0,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2};
    Solution1 s;
    cout<<s.increasingTriplet(test);
}