#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        vector<vector<int>> out(col, vector<int>(row));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                out[j][i] = A[i][j];
            }
        }
        return out;
    }
};