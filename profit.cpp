//
// Created by neha2 on 17-02-2022.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidRow(vector<vector<string>> &board, int r) {
        vector<string> row = board[r];
        row.erase(remove_if(row.begin(), row.end(), [](string c) { return c == "."; }), row.end());
        if (unique(row.begin(), row.end()) == row.end())
            return true;
        else
            return false;
    }

    bool isValidCol(vector<vector<string>> &board, int r, int c) {
        vector<string> col;
        for (int i = 0; i < 9; i++) {
            col.push_back(board[r][i]);
        }
        col.erase(remove_if(col.begin(), col.end(), [](string c) { return c == "."; }), col.end());
        if (unique(col.begin(), col.end()) == col.end())
            return true;
        else
            return false;

    }

    bool isValidDibba(vector<vector<string>> &board, int r, int c) {
        vector<string> dibba;
        int d_r = 3 * (r / 3);
        int d_c = 3 * (c / 3);
        for (int i = 0; i < 3; i++) {
            int d_c = 3 * (c / 3);
            for (int j = 0; j < 3; j++) {
                dibba.push_back(board[d_r][d_c]);
                d_c++;
            }
            d_r++;
        }
        dibba.erase(remove_if(dibba.begin(), dibba.end(), [](string c) { return c == "."; }), dibba.end());
        auto ip=unique(dibba.begin(), dibba.end());
        if ( ip == dibba.end())
            return true;
        else
            return false;
    }

    bool isValidSudoku(vector<vector<string>> &board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                bool rc = isValidRow(board, r);
                bool cc = isValidCol(board, r, c);
                bool dibba = isValidDibba(board, r, c);
                if (rc && cc && dibba)
                    continue;
                else {
                    return false;
                }
            }
        }
        return true;

    }
};

int main() {
    vector<vector<string>> v{
            {"8","3",".",".","7",".",".",".","."},
            {"6",".",".","1","9","5",".",".","."},
            {".","9","8",".",".",".",".","6","."},
            {"8",".",".",".","6",".",".",".","3"},
            {"4",".",".","8",".","3",".",".","1"},
            {"7",".",".",".","2",".",".",".","6"},
            {".","6",".",".",".",".","2","8","."},
            {".",".",".","4","1","9",".",".","5"},
            {".",".",".",".","8",".",".","7","9"}
    };
    Solution s;
    cout<<s.isValidSudoku(v);
}
