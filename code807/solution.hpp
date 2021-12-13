#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
//         int row = grid.size(), col = grid[0].size();
//         vector<int> row_max(row ,0);
//         vector<int> col_max(col, 0);
//         for (int i = 0; i< row; i++){
//             row_max[i] = *max_element(grid[i].begin(), grid[i].end());
//             for (int j=0; j<col; j++){
//                 col_max[j] = max(col_max[j], grid[i][j]);
//             }
//         }

//         int sum = 0;
//         for (int i = 0; i < row; i++){
//             for (int j = 0; j < col; j++){
//                 sum += (min(row_max[i], col_max[j]) - grid[i][j]);
//             }
//         }

//         return sum;
//     }
// };

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> max_grid_row(n, 0), max_grid_col(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                max_grid_row[i] = max(max_grid_row[i], grid[i][j]);
                max_grid_col[j] = max(max_grid_col[j], grid[i][j]);
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                res += min(max_grid_row[i], max_grid_col[j]) - grid[i][j];
            }
        }
        return res;
    }
};