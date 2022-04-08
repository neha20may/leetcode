//
// Created by neha2 on 31-03-2022.
//
class Solution {
public:
    int ans;
    vector<vector<int>> memo;
    void dfs(vector<vector<int>> &matrix,vector<vector<bool>> &visited, int & mx, vector<int> &partial_path, int i, int j){

        if(!visited[i][j]){

            visited[i][j]=true;
            partial_path.push_back(matrix[i][j]);
            if(static_cast<int>(partial_path.size())>mx)
            {
                mx=partial_path.size();

            }
            int m=matrix.size();
            int n=matrix[0].size();
            for(int k=-1;k<2;k++){
                int dx=i+k;
                int dy=j+k;
                if(dx>=0 and dx<m)
                    if(!visited[dx][j] and matrix[dx][j]>matrix[i][j])
                        dfs(matrix, visited, mx, partial_path, dx,j);
                if(dy>=0 and dy<n)
                    if(!visited[i][dy] and matrix[i][dy]>matrix[i][j])
                        dfs(matrix, visited, mx, partial_path, i, dy);
            }
            partial_path.pop_back();
            visited[i][j]=false;
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxS=-1;
        int m=matrix.size();
        int n=matrix[0].size();
        memo=vector<vector<int>>(m,vector<int>(n,0));
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                vector<int> partial_path;

                dfs(matrix, visited, maxS,partial_path,i,j);
            }
        return maxS;
    }
};
