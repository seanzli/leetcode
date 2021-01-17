#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;
        for (row = 0; row < matrix.size(); row++)
        {
            if ((matrix[row][0]<=target) && (matrix[row][matrix[row].size()-1] >= target))
                break;
            if (matrix[row][0]>target)
                return false;
        }
        if (find(matrix[row].begin(),matrix[row].end(), target) == matrix[row].end())
            return false;
        return true;
    }
};