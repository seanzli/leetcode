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

/* class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
}; */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res(row * col, 0);
        int flag = 0; // 0->right 1->down, 2->left 3->up
        int i_row = 0, i_col = 0;
        for (int i = 0; i < row * col; i++) {
            res[i] = matrix[i_row][i_col];
            matrix[i_row][i_col] = INT_MIN;
            if (flag == 0) {
                if (i_col + 1 == col || matrix[i_row][i_col + 1] == INT_MIN) {
                    flag = 1;
                    i_row++;
                } else {
                    i_col++;
                }
            } else if (flag == 1) {
                if (i_row + 1 == row || matrix[i_row + 1][i_col] == INT_MIN) {
                    flag = 2;
                    i_col--;
                } else {
                    i_row++;
                }
            } else if (flag == 2) {
                if (i_col == 0 || matrix[i_row][i_col - 1] == INT_MIN) {
                    flag = 3;
                    i_row--;
                } else {
                    i_col--;
                }
            } else {
                if (i_row == 0 || matrix[i_row - 1][i_col] == INT_MIN) {
                    flag = 0;
                    i_col++;
                } else {
                    i_row--;
                }
            }
        }
        return res;
    }
};