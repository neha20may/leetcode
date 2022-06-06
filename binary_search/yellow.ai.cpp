//
// Created by neha2 on 27-04-2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    pair<int, int> findRange(vector<int> &ip, int key) {
        pair<int, int> ans = {-1, -1};
        int first_index = bSearch(ip, key, 1);

        if (first_index == -1) {
            return ans;
        } else {
            int last_index = bSearch(ip, key, 2);
            ans.first = first_index;
            ans.second = last_index;
            return ans;
        }

    };

    int bSearch(vector<int> &ip, int key, int option) {
        int ans = -1;
        int start = 0;
        int end = ip.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (key < ip[mid]) {
                end = mid - 1;
            } else if (key > ip[mid]) {
                start = mid + 1;
            } else {
                ans = mid;
                if (option == 2) {
                    start = mid + 1;
                } else if (option == 1) {
                    end = mid - 1;//first index
                }
            }
        }
        return ans;
    }

};

int main() {
    vector<int> v = {1, 2, 3, 5, 5, 5, 8};
    Solution sl;
    int key = 5;
    pair<int, int> ans = sl.findRange(v, key);
    cout << "first posn=" << ans.first << " last posn=" << ans.second << endl;

}