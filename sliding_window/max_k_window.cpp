//
// Created by neha2 on 12-03-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void update_deque(deque<int> &d, int cur) {
        while (d.size() != 0) {
            if (d.back() < cur) {
                d.pop_back();
            } else
                break;
        }
        d.push_back(cur);
    }

    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        if (k == 1)
            return nums;
        if (n == 1)
            return nums;
        deque<int> d;
        vector<int> ans;
        int i = 0, j = 0;
        while (j < n) {
            cout<<"window : i= "<<i<<" j= "<<j<<" size= "<<j-i+1<<" [";
            copy(nums.begin()+i, nums.begin()+j+1, ostream_iterator<int>(cout, " ")); cout<<"]"<<endl;
            update_deque(d, nums[j]);
            cout<<"deque [";
            copy(d.begin(), d.end(), ostream_iterator<int>(cout, " ")); cout<<"]"<<endl;
            if (j - i + 1 < k) {
                //do nothing
            }

            if (j - i + 1 > k) {
                int oute = nums[i];
                int front = d.front();
                if (oute == front) {
                    //okay pop both
                    i++;
                    d.pop_front();
                }
                if (oute != front) {
                    i++;
                }
            }
            /**
             * This ordering of >k and ==k is very importtant here else it recalcualtes for j .
             */
            if (j - i + 1 == k) {
                int front = d.front();
                ans.push_back(front);
            }
            j++;
        }
        return ans;
    }
};

int main() {
    vector<int> v({-6,-10,-7,-1,-9,9,-8,-4,10,-5,2,9,0,-7,7,4,-2,-10,8,7});
    int k = 7;
    Solution s;
    vector<int> a = s.maxSlidingWindow(v, k);
    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

}
