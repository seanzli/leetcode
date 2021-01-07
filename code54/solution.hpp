#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <math.h>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;
        int i_num=0, row = matrix.size(), col = matrix[0].size();
        if (row==1)
            return matrix[0];
        if (col==1)
        {
            for (int i = 0; i < row; i++)
            {
                out.push_back(matrix[i][0]);
            }
            return out;
        }
        
        while ((i_num <= col/2) && (i_num <= row/2))
        {           
            for (int i = i_num; i < col-i_num-1; i++)
                out.push_back(matrix[i_num][i]);
            for (int i = i_num; i < row-i_num-1; i++)
                out.push_back(matrix[i][col-i_num-1]);
            for (int i = col-i_num-1; i >i_num; i--)
                out.push_back(matrix[row-i_num-1][i]);
            for (int i = row-i_num-1; i >i_num; i--)
                out.push_back(matrix[i][i_num]);

            i_num++;
        }
        
        if (out.size()<row*col)
        {
            if (row>col)
            {
                i_num = row/2;
                for (int i = i_num; i < row-i_num; i++)
                    out.push_back(matrix[i_num][i]);
            }
            else
            {
                i_num = col/2;
                for (int i = i_num; i < col-i_num; i++)
                    out.push_back(matrix[i][i_num]);
            }
            
        }
        return out;
    }
};