//
// Created by neha2 on 01-06-2022.
//
#include<bits/stdc++.h>

using namespace std;

class strategy {
public:
    virtual int longestValidParentheses(string s) = 0;
};

class pointer : public strategy {
public:
    int longestValidParentheses(string s) {
        int left_count = 0, right_count = 0;
        int ans = 0;
        //((())
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') left_count++;
            else right_count++;
            if (right_count > left_count) {
                left_count = 0;
                right_count = 0;
            } else if (left_count == right_count) {
                ans = max(ans, 2 * left_count);
            }
        }
        left_count = 0;
        right_count = 0;
        //(()))
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')') left_count++;
            else right_count++;
            if (right_count > left_count) {
                left_count = 0;
                right_count = 0;
            } else if (left_count == right_count) {
                ans = max(ans, 2 * left_count);
            }
        }
        return ans;

    }
};

class stackSt : public strategy {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        st.push(-1);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                st.push(i);
            } else {
                if (st.empty())
                    st.push(i);
                else {
                    st.pop();
                    if (st.empty())
                        st.push(i);
                    else {
                        ans = max(ans, i - st.top());
                    }
                }
            }
        }
        return ans;
    }
};

class dp : public strategy {
public:
    int longestValidParentheses(string s) {

        int n = s.length();
        if (n <= 1) return 0;
        //We make use of a dp array where ith element of dp represents the length of the longest valid substring ending at ith index.
        vector<int> dp(n, 0);
        //for ( -->0
        //for..() && ))
        for (int i = 1; i < n; i++) {
            if (s[i] == ')' && s[i - 1] == '(') {
                dp[i] = 2;
                if (i - 2 >= 0)
                    dp[i] += dp[i - 2];
            }

            if (s[i] == ')' && s[i - 1] == ')') {
                int charIndex = i - dp[i - 1] - 1;
                int index = i - dp[i - 1] - 2;
                if (charIndex >= 0 && s[charIndex] == '(') {
                    dp[i] = dp[i - 1];
                    dp[i] += 2;
                    if (index >= 0)
                        dp[i] += dp[index];
                }

            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

//context
class Solution {
    strategy *stgy;
public:
    Solution(strategy *stgy) {
        this->stgy = stgy;
    }

    Solution() {
        this->stgy = new pointer();
    }

//execute strategy
    int longestValidParentheses(string s) {
        return stgy->longestValidParentheses(s);
    }
};

int main() {
    Solution *S = new Solution(new dp());
    int ans = S->longestValidParentheses("()()))))()()(");
    cout << ans << endl;
    return 0;
}