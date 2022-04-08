//
// Created by neha2 on 29-03-2022.
//
#include <bits/stdc++.h>

using namespace std;

//
// Created by neha2 on 31-03-2022.
//
class Solution {
public:
    int ans;
    vector<vector<int>> memo;
    vector<vector<bool>> visited;
    int m, n;
    int dfs(vector<vector<int>> &matrix, int i, int j) {
        if(memo[i][j]!=-1)
            return  memo[i][j];
        else{
            visited[i][j]=true;
            vector<int> dfs_calls;
            dfs_calls.push_back(0);
            for(int k=-1; k<2;k++){
                int dx=i+k;
                int dy=j+k;
                if(dx<m && dx>=0 && !visited[dx][j] && matrix[dx][j]>matrix[i][j]){
                    if(memo[dx][j]!=-1)
                        dfs_calls.push_back(memo[dx][j]);
                    else
                    {
                        memo[dx][j]=dfs(matrix, dx,j);
                        dfs_calls.push_back(memo[dx][j]);
                    }
                }
                if(dy<n && dy>=0 && !visited[i][dy] && matrix[i][dy]>matrix[i][j]){
                    if(memo[i][dy]!=-1)
                        dfs_calls.push_back(memo[i][dy]);
                    else
                    {
                        memo[dx][j]=dfs(matrix, dx,j);
                        dfs_calls.push_back(memo[i][dy]);
                    }
                }
            }
            int ans=1+*max_element(dfs_calls.begin(), dfs_calls.end());
            memo[i][j]=ans;
        };
        visited[i][j]= false;
        return memo[i][j];

    }

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int maxS = -1;
        m = matrix.size();
        n = matrix[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                memo[i][j] = dfs(matrix, i, j);
                maxS=max(maxS, memo[i][j]);
            }
        return maxS;
    }

};


int main() {
    Solution s;
//    vector<vector<int>> mat = {{0,   1,   2,   3,   4,   5,   6,   7,   8,   9},
//                               {19,  18,  17,  16,  15,  14,  13,  12,  11,  10},
//                               {20,  21,  22,  23,  24,  25,  26,  27,  28,  29},
//                               {39,  38,  37,  36,  35,  34,  33,  32,  31,  30},
//                               {40,  41,  42,  43,  44,  45,  46,  47,  48,  49},
//                               {59,  58,  57,  56,  55,  54,  53,  52,  51,  50},
//                               {60,  61,  62,  63,  64,  65,  66,  67,  68,  69},
//                               {79,  78,  77,  76,  75,  74,  73,  72,  71,  70},
//                               {80,  81,  82,  83,  84,  85,  86,  87,  88,  89},
//                               {99,  98,  97,  96,  95,  94,  93,  92,  91,  90},
//                               {100, 101, 102, 103, 104, 105, 106, 107, 108, 109},
//                               {119, 118, 117, 116, 115, 114, 113, 112, 111, 110},
//                               {120, 121, 122, 123, 124, 125, 126, 127, 128, 129},
//                               {139, 138, 137, 136, 135, 134, 133, 132, 131, 130},
//                               {0,   0,   0,   0,   0,   0,   0,   0,   0,   0}};
    vector<vector<int>> mat = {
            {9, 9, 4},
            {6, 6, 8},
            {2, 1, 1}
    };
    cout << "longest increaing path=" << s.longestIncreasingPath(mat) << endl;
}
