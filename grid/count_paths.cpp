//
// Created by neha2 on 08-04-2022.
//

#include<bits/stdc++.h>

using namespace std;

long long countPaths(vector<vector<int>> &matrix, int source, int target,
                     vector<bool> &visited, vector<vector<int>> &memo) {
    cout << source << " " << target << endl;
    if (source == target) {
        memo[source][target] = 1;
        return memo[source][target];
    }
    if (memo[source][target] != -1)
        return memo[source][target];
    int N = matrix.size() - 1;
    visited[source] = true;
    memo[source][target] = 0;
    for (int k = source + 1; k <= N; k++) {
        if (matrix[source][k] == 1) {
            if (visited[k] == false) {
                cout << " k and target in  memo " << memo[k][target] << endl;
                if (memo[k][target] != -1)
                    return 1 + memo[k][target];
                else {
                    memo[source][target] += 1 + countPaths(matrix, k, target, visited, memo);
                }
            }
        }
    }
    visited[source] = false;
    return memo[source][target];
}

long long solve(int N) {
    // Write your code here
    if (N == 1)
        return 0;
    vector<vector<int>> matrix(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        matrix[i][i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int res = j % i;
            if (res == 0) {
                matrix[i][j] = 1;
            }
        }
    }
    vector<bool> visited(N + 1, false);
    //calculate the no of paths from 1 to N
    long long result = 0;
    vector<vector<int>> memo(N + 1, vector<int>(N + 1, -1));
    countPaths(matrix, 1, N, visited, memo);
    for (auto v: memo) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return memo[1][N];

}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++) {
        int N;
        cin >> N;

        long long out_;
        out_ = solve(N);
        cout << out_;
        cout << "\n";
    }
}