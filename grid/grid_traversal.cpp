//
// Created by neha2 on 23-02-2022.
//

#include <bits/stdc++.h>

using namespace std;
void dfs(vector<vector<int> > grid, int r, int c){

}
int main(){
    int r, c;
    vector<vector<int> > grid;
    int m, n;
    //Conditions for traversing the grid.
    if(r>=1 && grid[r-1][c]=='1') dfs(grid, r-1, c);
    if(r<m-1 && grid[r+1][c]=='1') dfs(grid, r+1, c);
    if(c>=1 && grid[r][c-1]=='1') dfs(grid, r, c-1);
    if(c<n-1 && grid[r][c+1]=='1') dfs(grid, r, c+1);

}