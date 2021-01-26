#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int i = row-1, j=0;
        while ((j<col)&&(i>=0)){
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                i--;
            else
                j++;
        }
        return false;
    }
};