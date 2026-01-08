#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> row_zero;
        vector<int> col_zero;
        for(int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    row_zero.push_back(i);
                    col_zero.push_back(j);
                }
            }
        }
        //making whole row zero
        for(int r:row_zero){
            for(int i=0;i<cols;i++){
                matrix[r][i]=0;
            }
        }

        //making whole column zero
        for(int c:col_zero){
            for(int i=0;i<rows;i++){
                matrix[i][c]=0;
            }
        }

        

    }
};