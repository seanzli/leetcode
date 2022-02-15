#include <vector>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> min_row(row, INT_MAX);
        vector<int> max_col(col, INT_MIN);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                min_row[i] = min(min_row[i], matrix[i][j]);
                max_col[j] = max(max_col[j], matrix[i][j]);
            }
        }
        vector<int> res;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == min_row[i] && matrix[i][j] == max_col[j])
                    res.emplace_back(matrix[i][j]);
            }
        }
        return res;
    }
};