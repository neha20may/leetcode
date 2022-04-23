//
// Created by neha2 on 23-04-2022.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct my_bitset{
        int count;
        vector<unsigned  int> bitset;
    };

    vector<my_bitset> zero_bits_end;
    vector<my_bitset> one_bits_end;

    int getNo(int i) {
        if (i == 0)
            return 1;
        int count = zero_bits_end[i].count+ one_bits_end[i].count;
        return count;
    }
    vector<unsigned int> getMask(int i) {
        if (i == 0)
            return vector<unsigned int>();
        vector<unsigned int> result;
        for(auto x:zero_bits_end[i].bitset){
            result.push_back(x);
        }
        for(auto x:one_bits_end[i].bitset){
            result.push_back(x);
        }
        return result;
    }

    /**
    This count of bit string ending at 0 and ending at 1 makes a fibbonacci sequence!
    For understanding pupose, I went for zero/one, it can be optimised simply for fibbonacci.
    for (int i = 2; i < 32; ++i)
            f[i] = f[i-1]+f[i-2];
    */
    vector<unsigned int>
    getBitSet(vector<my_bitset> zero_bits_end,
              vector<my_bitset> one_bits_end, int index, bool flag) {
        vector<unsigned int> result;
        if (flag) {
            vector<unsigned int> zero = zero_bits_end[index].bitset;
            vector<unsigned int> one = one_bits_end[index].bitset;

            for (auto x: zero) {
                unsigned int y = x << 1;
                result.push_back(y);
            }
            for (auto x: one) {
                unsigned int y = x << 1;
                result.push_back(y);
            }
        } else {
            vector<unsigned int> zero = zero_bits_end[index].bitset;

            for (auto x: zero) {
                unsigned int y = (x << 1) + 1;
                result.push_back(y);
            }
        }
        return result;
    }

    void init(int B) {
        int bits = floor(log2(B)) + 1;

        // cout<<"bits "<<bits<<endl;
        zero_bits_end[0].count = 1;
        one_bits_end[0].count = 1;
        zero_bits_end[1].count = 1;
        zero_bits_end[1].bitset= vector<unsigned int>(1, 0);
        one_bits_end[1].count = 1;
        one_bits_end[1].bitset = vector<unsigned int>(1, 1);
        for (int i = 2; i <= bits; i++) {
            zero_bits_end[i].count = zero_bits_end[i - 1].count + one_bits_end[i - 1].count;
            zero_bits_end[i].bitset = getBitSet(zero_bits_end, one_bits_end, i-1, true);
            one_bits_end[i].count = zero_bits_end[i - 1].count;
            one_bits_end[i].bitset = getBitSet(zero_bits_end, one_bits_end, i-1, false);
        }
    }

    int findIntegers(int n) {
        int B = log2(n) + 1;
        zero_bits_end.resize(B +1);
        one_bits_end.resize(B + 1);
        init(n);
        //find position of ones
        int pos = 0;
        vector<int> ones;
        unsigned int number = n;
        while (number) {
            if (number & 1) {
                ones.push_back(pos);
            }
            number = number >> 1;
            pos++;
        }
        int N = ones.size() - 1;
        int ans = 0;
        bool flag = false;
        vector<unsigned int> masks;
        for (int i = N; i >= 0; i--) {
            //if consecutive ones, stop!
            if (i >= 1 && ones[i] == ones[i - 1] + 1) {
                ans += getNo(ones[i]);
                for(auto m: getMask(ones[i]))
                    masks.push_back(m);
                ans += getNo(ones[i - 1]);
                for(auto m: getMask(ones[i-1]))
                    masks.push_back(m);
                flag = true;
                break;
            } else {
                ans += getNo(ones[i]);
                for(auto m: getMask(ones[i]))
                    masks.push_back(m);
            }

        }
        ans = ans + 1; //add this element too

        if (flag) {
            ans = ans - 1;
        }
        return ans;

    }

public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        unsigned int h_no = (unsigned) n;
        int count_masks = findIntegers(n);
        int bits = log2(n) + 1;
        vector<unsigned int> end_zeros = zero_bits_end[bits].bitset;
        vector<unsigned int> end_ones = one_bits_end[bits].bitset;
        vector<unsigned int> masks;
        for(auto x: end_zeros)
            masks.push_back(x);
        for(auto x: end_ones)
            masks.push_back(x);
        int ans = 0;
        for (auto mask: masks) {
            int profit = 0;
            for (int i = 0; i < h_no; i++) {
                if (mask & (1 << i)) {
                    profit += nums[i];
                }
            }
            ans = max(ans, profit);
        }
    }
};

int main() {
    Solution sl;
    vector<int> h = {1, 2, 3, 1};
    sl.rob(h);
}