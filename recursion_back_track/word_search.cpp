//
// Created by neha2 on 24-02-2022.
//
/**
 * For the backtracking function backtrack(row, col, suffix), as a DFS algorithm, it is often implemented as a recursive function. The function can be broke down into the following four steps:

Step 1). At the beginning, first we check if we reach the bottom case of the recursion, where the word to be matched is empty, i.e. we have already found the match for each prefix of the word.

Step 2). We then check if the current state is invalid, either the position of the cell is out of the boundary of the board or the letter in the current cell does not match with the first letter of the word.

Step 3). If the current step is valid, we then start the exploration of backtracking with the strategy of DFS. First, we mark the current cell as visited, e.g. any non-alphabetic letter will do. Then we iterate through the four possible directions, namely up, right, down and left. The order of the directions can be altered, to one's preference.

Step 4). At the end of the exploration, we revert the cell back to its original state. Finally we return the result of the exploration.
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<basic_string<char>> ans;
public:
    void dfs(vector<vector<char>> &board, int i, int j, string word, int count) {
        if (count == 0) {
            this->ans = true;
            return;
        } else {
            int m = board.size();
            int n = board[0].size();
            if (board[i][j] != '1')
                if (word[0] == board[i][j]) {
                    char x = word[0];
                    word.erase(word.begin() + 0);
                    board[i][j] = '1';
                    if (i > 0 && ans == false)
                        dfs(board, i - 1, j, word, count - 1);
                    if (i < m - 1 && ans == false)
                        dfs(board, i + 1, j, word, count - 1);
                    if (j > 0 && ans == false)
                        dfs(board, i, j - 1, word, count - 1);
                    if (j < n - 1 && ans == false)
                        dfs(board, i, j + 1, word, count - 1);
                    word.insert(0, 1, x);
                    board[i][j] = x;
                } else {
                    return;
                }
        }
    }

    bool exist(vector<vector<char>> &board, string word) {
        this->ans = false;
        int m = board.size();
        int n = board[0].size();
        int count = word.size();
        if (m == 1 && n == 1 && count == 1) {
            if (board[0][0] == word[0])
                return true;
            else
                return false;
        }
        if (m * n < count)
            return false;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!ans) dfs(board, i, j, word, count);
        return ans;
    }
};

int main() {
//    vector<vector<char> > grid = {
//            {'A', 'B', 'C', 'E'},
//            {'S', 'F', 'C', 'S'},
//            {'A', 'D', 'E', 'E'}
//    };
//    vector<vector<char>> grid = {{'a', 'a'}};
    vector<vector<char>> grid = {
            {'a', 'b', 'c'},
            {'a', 'e', 'd'},
            {'a', 'f', 'g'}
    };
    string word = "abcdefg";
    Solution s;
    cout << s.exist(grid, word);
}