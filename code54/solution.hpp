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
/*         if (row==1)
            return matrix[0];
        if (col==1)
        {
            for (int i = 0; i < row; i++)
            {
                out.push_back(matrix[i][0]);
            }
            return out;
        } */
        
        while (1)
        {
            for (int i = i_num; i < col-i_num-1; i++)
                out.push_back(matrix[i_num][i]);
            if (out.size()==row*col)
                return out;
            for (int i = i_num; i < row-i_num-1; i++)
                out.push_back(matrix[i][col-i_num-1]);
            if (out.size()==row*col)
                return out;
            for (int i = col-i_num-1; i >i_num; i--)
                out.push_back(matrix[row-i_num-1][i]);
            if (out.size()==row*col)
                return out;
            for (int i = row-i_num-1; i >i_num; i--)
                out.push_back(matrix[i][i_num]);
            if (out.size()==row*col)
                return out;
            i_num++;
        }
        
        return out;
    }
};