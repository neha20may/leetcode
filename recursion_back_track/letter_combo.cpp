//
// Created by neha2 on 20-02-2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> cross(vector<string> a, vector<string> b) {
        vector<string> result;
        for (auto x: a)
            for (auto y: b) {
                result.push_back(x + y);
            }
        return result;
    }

    vector<string> solve(string digits, unordered_map<char, vector<string>> m) {
        if (digits.length() == 0) {
            return vector<string>();
        } else if (digits.length() == 2) {
            vector<string> op = cross(m[digits[0]], m[digits[1]]);
            return op;
        } else {
            char first_digit = digits[0];
            vector<string> v = m[first_digit];
            digits.erase(digits.begin() + 0);
            vector<string> rest_cross = solve(digits, m);
            vector<string> op = cross(v, rest_cross);
            return op;
        }
    }

    void solve2(string digits, string op, vector<string> &ans,unordered_map<char, vector<string>> m ) {
        if(digits.length()==0)
        {
            ans.push_back(op);
            return;
        }
        else{
            vector<string> choices=m[digits[0]];
            digits.erase(digits.begin()+0);
            for(string choice: choices){
                string op_new=op+choice;
                solve2(digits, op_new, ans, m);
            }
        }
    }
    /**
     * Leetcode solution using backtrack
     * @param digits
     * @return
     */
//private void backtrack(int index, StringBuilder path) {
//        // If the path is the same length as digits, we have a complete combination
//        if (path.length() == phoneDigits.length()) {
//            combinations.add(path.toString());
//            return; // Backtrack
//        }
//
//        // Get the letters that the current digit maps to, and loop through them
//        String possibleLetters = letters.get(phoneDigits.charAt(index));
//        for (char letter: possibleLetters.toCharArray()) {
//            // Add the letter to our current path
//            path.append(letter);
//            // Move on to the next digit
//            backtrack(index + 1, path);
//            // Backtrack by removing the letter before moving onto the next
//            path.deleteCharAt(path.length() - 1);
//        }
//    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<string>> m;
        m['2'] = {"a", "b", "c"};
        m['3'] = {"d", "e", "f"};
        m['4'] = {"g", "h", "i"};
        m['5'] = {"j", "k", "l"};
        m['6'] = {"m", "n", "o"};
        m['7'] = {"p", "q", "r", "s"};
        m['8'] = {"t", "u", "v"};
        m['9'] = {"w", "x", "y", "z"};
        vector<string> ans = solve(digits, m);
        return ans;
    }
    vector<string> letterCombinations2(string digits) {
        unordered_map<char, vector<string>> m;
        m['2'] = {"a", "b", "c"};
        m['3'] = {"d", "e", "f"};
        m['4'] = {"g", "h", "i"};
        m['5'] = {"j", "k", "l"};
        m['6'] = {"m", "n", "o"};
        m['7'] = {"p", "q", "r", "s"};
        m['8'] = {"t", "u", "v"};
        m['9'] = {"w", "x", "y", "z"};
        vector<string> ans;
        string op="";
        solve2(digits, op, ans, m);
        return ans;
    }
};

int main() {
    string digits = "23";
    //op: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    Solution s;
    vector<string> ans;
    ans = s.letterCombinations(digits);
    for (auto a: ans)
        cout << a << " ";
    cout<<endl;
    ans.clear();
    ans=s.letterCombinations2(digits);
    for (auto a: ans)
        cout << a << " ";
    cout << endl;

}
