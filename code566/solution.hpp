#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size(), col = nums[0].size();
        if (row*col != r*c) return nums;

        vector<int> matrix(row*col, 0);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                matrix[i*row+j] = nums[i][j];
            }
        }
        
        vector<vector<int>> out(r, vector<int>(c));
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                out[i][j] = matrix[i*r+j];
            }
        }
        return out;
    }
};