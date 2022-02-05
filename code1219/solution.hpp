#include <vector>

using namespace std;

class Solution {
    size_t row, col;
    int res;
    int step[4][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        res = 0;
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < col; ++j) {
                if (grid[i][j] != 0) {
                    vector<vector<bool>> visited(row, vector<bool>(col, false));
                    dfs(grid, i, j, visited, 0);
                }
            }
        }
        return res;
    }

    void dfs(const vector<vector<int>>& grid, const int i, const int j, vector<vector<bool>>& visited, int cur) {
        if (i < 0 || i == row || j < 0 || j == col || grid[i][j] == 0 || visited[i][j]) {
            res = max(cur, res);
            return;
        }
        cur += grid[i][j];
        visited[i][j] = true;

        dfs(grid, i + 1, j, visited, cur);
        dfs(grid, i, j + 1, visited, cur);
        dfs(grid, i - 1, j, visited, cur);
        dfs(grid, i, j - 1, visited, cur);

        visited[i][j] = false;
    }
};