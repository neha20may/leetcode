//
// Created by Neha on 22/08/22.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findFirstOccur(int target, vector<int> &v) {
        int start = 0, end = v.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (v[mid] > target) {
                end = mid - 1;
            } else if (v[mid] < target) {
                start = mid + 1;
            } else {
                if (mid - 1 >= 0 && v[mid - 1] == target) {
                    end = mid - 1;
                } else {
                    return mid;
                }
            }
        }
        return -1;
    }

    int findLastOccur(int target, vector<int> &v) {
        int start = 0, end = v.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (v[mid] > target) {
                end = mid - 1;
            } else if (v[mid] < target) {
                start = mid + 1;
            } else {
                if (mid + 1 <= v.size() - 1 && v[mid + 1] == target) {
                    start = mid + 1;
                } else {
                    return mid;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> v = {1, 2, 2, 2, 2, 3, 4, 4, 4, 4, 5, 6};
    Solution s;
    cout << s.findFirstOccur(7, v)<<endl;
    cout << s.findLastOccur(7, v);
}
