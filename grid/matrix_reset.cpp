//
// Created by neha2 on 04-03-2022.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void print(vector<vector<int>>& matrix){
        for(auto v:matrix){
            for(auto a:v)
            {
                cout<<a<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    void clear_row(vector<vector<int>>&matrix, int i){
        int m=matrix.size();
        int n=matrix[0].size();
        for(int k=0;k<n;k++){
            matrix[i][k]=0;
        }
    }
    void clear_column(vector<vector<int>>&matrix, int j){

        int m=matrix.size();
        int n=matrix[0].size();
        for(int k=0;k<m;k++){
            matrix[k][j]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int first_col=1;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                 if(i!=0 and j==0){
                    matrix[i][0]=0;
                }
                else{
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        print(matrix);
        //traverse first row
        //traverse first col
        for(int col=1;col<n;col++){
            if(matrix[0][col]==0)
                clear_column(matrix,col);
        }
        print(matrix);
        for(int row=1;row<m;row++){
            if(matrix[row][0]==0)
                clear_row(matrix,row);
        }
        print(matrix);
        if(matrix[0][0]==0 and first_col==0)
        {
            clear_row(matrix,0);
            clear_column(matrix, 0);
        }
        print(matrix);
    }
};

int main() {
    vector<vector<int>> v = {
            {1,1,1},
            {1,0,1},
            {1,1,1}
    };
    //[[1,1,1],[1,0,1],[1,1,1]]
    Solution s;
    s.print(v);
    s.setZeroes(v);
}