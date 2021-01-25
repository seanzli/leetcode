#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int row, col;
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_sqre = 0;
        row = matrix.size();
        col = matrix[0].size();
        for (int i_row = 0; i_row < row; i_row++)
        {
            for (int i_col = 0; i_col < col; i_col++)
            {
                if (matrix[i_row][i_col] == '1'){
                    int sqre = getMaxSqre(matrix, i_row, i_col);
                    max_sqre = max(max_sqre, sqre);
                }
            }
        }
        return max_sqre;
    }
    int getMaxSqre(vector<vector<char>>& matrix, int i_row, int i_col){
        int length = 1;
        for (; i_row+length<row && i_col+length<col; length++)
        {
            for (int i = i_row; i <= i_row+length; i++)
            {
                if (matrix[i][i_col+length]=='0')
                    return length*length;
            }
            for (int i = i_col; i <= i_col+length; i++)
            {
                if (matrix[i_row+length][i]=='0')
                    return length*length;
            }
        }
        return length*length;
    }
};