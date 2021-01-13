#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>


using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int max_area = 0;
        int row = matrix.size();
        if (row < 1)
            return max_area;
        int col = matrix[0].size();
        for (int i_row = 0; i_row < row; i_row++)
        {
            for (int i_col = 0; i_col < col; i_col++)
            {
                if (matrix[i_row][i_col]=='1')
                {
                    max_area = max(max_area, genArea(matrix, i_row, i_col));
                }

            }
            
        }
        return max_area;
    }
    int genArea(vector<vector<char>>& matrix, int row, int col){
        int cur_area = 0;
        int max_area = 0;
        int max_idx = 0;
        if ((row == 3) && (col == 6))
        {
            int test = 1;
        }
        
        for (int i = row; i >= 0; i--)
        {
            cur_area = 0;
            for (int j = col; j >= max_idx; j--)
            {
                if (matrix[i][j] == '1')
                    cur_area++;
                else
                {
                    max_idx = j+1;
                    break;
                }
            }
            cur_area = cur_area*(row-i+1);
            if (cur_area==0)
                break;
            max_area = max(max_area, cur_area);
        }
        return max_area;
    }
};