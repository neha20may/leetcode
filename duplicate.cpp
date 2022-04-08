//
// Created by neha2 on 10-02-2022.
//
/**
 * Phewww ! what a question!
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool overflow_sum(int num, int x_digit, int sign) {
        int max = numeric_limits<int>::max();
        int min = numeric_limits<int>::min();
        if ((sign == 1) && num > max - x_digit) {
            return true;
        } else {
            if ((sign == -1) && num < min - x_digit) {
                return true;
            } else {
                return false;
            }
        }

    }

    void get_exp(int &exp) {
        int max = numeric_limits<int>::max();
        int min = numeric_limits<int>::min();
        if ((exp > 0) && (exp > max / 10)) {
            throw overflow_error("10 overflow");
        } else if ((exp < 0) && (exp < min / 10))
            throw overflow_error("-10 overflow");
        else
            exp = exp * 10;

    }

    int get_digit(int &exp, int digit) {
        int max = numeric_limits<int>::max();
        int min = numeric_limits<int>::min();
        if (digit == 0)
            return 0;
        if ((exp > 0) && (exp > max / digit))
            throw overflow_error("+ digit overflow");
        else if ((exp < 0) && (exp < min / digit))
            throw overflow_error("- digit overflow");
        else
            return exp * digit;
    }

    int reverse(long long int x) {
        if (!x)
            return 0;
        int n = log10(abs(x))+1;
        vector<int> v;
        int num_given = x;
        while (x) {
            int d = x % 10;
            v.push_back(d);
            x = x / 10;
        }
        std::reverse(v.begin(), v.end());
        auto ri = v.rbegin();
        while (ri != v.rend()) {
            if (*ri == 0) {
                ri++;
                v.pop_back();
            } else {
                break;
            }
        }
        // copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); cout<<endl;
        int i = 0;
        int num = 0;
        int sign = (num_given >= 0) ? 1 : -1;
        int exp = sign * pow(10, 0);

        for (auto x: v) {
            try {
                int x_digit = get_digit(exp, abs(x));
                if (!overflow_sum(num, x_digit, sign)) {
                    num += x_digit;
                } else {
                    num = 0;
                    break;
                }

                i++;
                if(i==n)
                    break;
                get_exp(exp);
            }
            catch (overflow_error e) {
                cout << e.what() << endl;
                num = 0;
                break;
            }
        }
        return num;
    }
};

int main() {
    Solution s;
    int p = s.reverse(-2147483412);
    cout << "profit " << p << endl;
}
