//
// Created by neha2 on 12-06-2022.
//
//TODO: revise subsequence and K problems
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long ans;
    vector<vector<int>> dpodd;
    vector<vector<int>> dpeven;

    void solve(int index, int k, long long partial_sum, vector<int> &nums, int n) {
        if (index >= n) {
            if (k == 0 && partial_sum % 2 == 0) {
                ans = max(ans, partial_sum);
                dpeven[index][k] = partial_sum;
                return;
            }
            return;
        }
        if (k == 0) {
            if (partial_sum % 2 == 0) {
                ans = max(ans, partial_sum);
                dpeven[index][k] = partial_sum;
                return;
            }
            return;
        }

        int cur = nums[index];
        //TODO: partial sum ka even and odd concept  ??
        long long new_sum = partial_sum + cur;
        /**
    //input 4 1 3 5
                             index=0  k=3  () psum=0
                     i=1 k=2 (4) psum=4                                              () psum=0 k=3
               i=2k=1(41)(5)                                   k=2(4)(4)                      (1) (1)k=2                   ()(0) k=3
i=3:k=0(413)(8)     k=1(41)(5)                   k=1(43)(7)         k=2(4)(4)              (13)(4)k=1  (1)(1)k=2      (3)(3)k=2  ()(0)k=3
i=4(0)r8;     (0)(415)(10);(1)(41)(5)   (0)(435)(12);(1)(43)(7) (1)(45)(9);(2)(4)(4)
*/

        solve(index + 1, k - 1, new_sum, nums, n);
        solve(index + 1, k, partial_sum, nums, n);

//        if(new_sum % 2 == 0){
//            dpeven[index][k] = new_sum;
//        }
//        if(new_sum % 2 == 1){
//            dpodd[index][k] = new_sum;
//        }

        if (cur % 2 != 0) {
            dpodd[index][k] = cur + ((dpeven[index + 1][k] != 0) ? dpeven[index + 1][k] : 0);
            dpeven[index][k] = (dpodd[index + 1][k] != 0) ? dpodd[index + 1][k] + cur : dpeven[index + 1][k];
        }

        if (cur % 2 == 0) {
            dpodd[index][k] = (dpodd[index][k] + 1 != 0) ? dpodd[index + 1][k] + cur : 0;
            dpeven[index][k] = dpeven[index + 1][k] + cur;
        }

    }

    long long dp(vector<int> &nums) {
        /**
        A[i] is odd;
		oddsum[i]= a[i]+(evensum[i+1]!=0):evensum[i+1]:0;
		evenSum[i]= (oddSum[i+1]!=0):oddsum[i+1]+a[i]:evensum[i+1];
        A[i] is even
		Oddsum[i]=(odd[i+1]!=0):oddsum[i+1]+a[i]:0;
        evenSum[i]=evensum[i+1]+a[i];
        */
        int n = nums.size();
        vector<long long> odd(n, 0);
        vector<long long> even(n, 0);
        if (nums[n - 1] % 2 == 0) {
            even[n - 1] = nums[n - 1];
        } else {
            odd[n - 1] = nums[n - 1];
        }

        cout << "odd::";
        for (auto x: odd)
            cout << x << " ";
        cout << endl;
        cout << "even:";
        for (auto x: even)
            cout << x << " ";
        cout << endl;

        for (int i = n - 2; i >= 0; --i) {
            int cur = nums[i];
            cout << "current no=" << cur << endl;

            if (cur % 2 != 0) {
                odd[i] = cur + ((even[i + 1] != 0) ? even[i + 1] : 0);
                even[i] = (odd[i + 1] != 0) ? odd[i + 1] + cur : even[i + 1];
            }

            if (cur % 2 == 0) {
                odd[i] = (odd[i + 1] != 0) ? odd[i + 1] + cur : 0;
                even[i] = even[i + 1] + cur;
            }


            cout << "odd::";
            for (auto x: odd)
                cout << x << " ";
            cout << endl;
            cout << "even:";
            for (auto x: even)
                cout << x << " ";
            cout << endl;
        }

        long long ans = *max_element(even.begin(), even.end());
        return ans;

    }

    long long largestEvenSum(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 1) {
            if (nums[0] % 2 == 0)
                return nums[0];
            else
                return -1;
        }
        ans = -1;
        dpodd.resize(n+1, vector<int>(k, 0));
        dpeven.resize(n+1, vector<int>(k, 0));
        solve(0, k, 0, nums, n);
        // ans=dp(nums);

        return ans;
    }
};

int main() {
    vector<int> nums = {4, 1, 3, 5};
    Solution s;
    cout << s.largestEvenSum(nums, 4) << endl;
}