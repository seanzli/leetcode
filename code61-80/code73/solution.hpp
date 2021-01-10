#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> idx;
        pair<int, int> cur;
        int rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i<rows; i++)
        {
            vector<int>::iterator start = matrix[i].begin();
            while ((start = find(start, matrix[i].end(), 0))!=matrix[i].end())
            {
                cur.first = i; 
                cur.second = distance(matrix[i].begin(), start);
                idx.push_back(cur);
                start++;
            }
        }
        for (auto i : idx)
        {
            for (int i_row = 0; i_row < rows; i_row++)
                matrix[i_row][i.second]=0;
            for (int i_col = 0; i_col < cols; i_col++)
                matrix[i.first][i_col]=0;
        }
    }
};