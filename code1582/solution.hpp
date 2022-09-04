#include <vector>

using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> sum_row(row, 0);
        vector<int> sum_col(col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                sum_row[i] += mat[i][j];
                sum_col[j] += mat[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (mat[i][j] == 1 && sum_row[i] == 1 && sum_col[j] == 1)
                    ++res;
            }
        }

        return res;
    }
};