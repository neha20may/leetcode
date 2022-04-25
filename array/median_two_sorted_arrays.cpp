//
// Created by neha2 on 25-
#include <bits/stdc++.h>
// avinash.verma@stanzaliving.com
using namespace std;

//
// Created by neha2 on 25-
#include <bits/stdc++.h>
// avinash.verma@stanzaliving.com
using namespace std;
/**
 * edge case1:
 * nums1={1}
 * nums2={4}
 * first cut -INF(top left) |  1 (top right)     INF
 *           -INF    4 (bottom left)  |  INF (bottom right)
 *        Not valid cut, bottom left(4) !< top right(INF) right so move cut
 *         -INF   1   |  INF
 *       -INF  |  4      INF
 *       now 1<4 and -INF<INF
 *       All elements to left should be lesser than all elements to right of cut.
 *
 *      Example 2:
 *      -INF | 4 INF
 *      -INF 1 | INF
 *      Valid cut!
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        //Edge cases for leetcode
        if (n1 == 0 && n2 == 0) {
            return 0;
        }
        if(n1==1 && n2==0){
            return nums1[0];
        }
        if(n1==0 && n2==1){
            return nums2[0];
        }
        //swap for smaller array
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);


        /**
         * Not needed wrote edges cases for leetcode above.
         */
        double median = 0;

        int low = 0, high = nums1.size();
        int total = n1 + n2;
        while (low <= high) {
            //cut it
            int top_cut = (low + high) / 2; //change it later
            int bottom_cut = (total + 1) / 2 - top_cut;

            //those 4 elements to check if it is valid else move for valid

            int top_right;
            if (top_cut != nums1.size()) {
                top_right = nums1[top_cut]; //length
            } else {
                top_right = INT_MAX; //This was causing error; I wrote INT MIN by mistake
            }
            int top_left;
            if (top_cut != 0) {
                top_left = nums1[top_cut - 1];
            } else {
                top_left = INT_MIN;
            }

            int bottom_right;
            if (bottom_cut != nums2.size()) {
                bottom_right = nums2[bottom_cut]; //length
            } else {
                bottom_right = INT_MAX;
            }
            int bottom_left;
            if (bottom_cut != 0) {
                bottom_left = nums2[bottom_cut - 1]; //0
            } else {
                bottom_left = INT_MIN;
            }
            if (top_left <= bottom_right && bottom_left <= top_right) {
                if (total % 2 == 0) {
                    int v1 = max(top_left, bottom_left);
                    int v2 = min(top_right, bottom_right);
                    median = (v1 + v2) / 2.0;
                } else {
                    int v1 = max(top_left, bottom_left);
                    median = v1;
                }
                return median;
            } else if (top_left > bottom_right) {
                high = top_cut - 1; //search smaller //Mistake, wrote low here
            } else if (bottom_left > top_right) {
                low = top_cut + 1; //search larger //Mistake, wrote low here
            }

        }
        return median;

    }
};


int main(){
    Solution sl;
    vector<int> v1{1};
    vector<int> v2{4};
    cout<<"median found is="<<sl.findMedianSortedArrays(v1, v2);
}