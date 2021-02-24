#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* class Solution {
    int row, col;
    vector<vector<int>> res;
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        row = obstacleGrid.size();
        col = obstacleGrid[0].size();
        if (dfs(obstacleGrid, 0, 0))
            return res;
        else
            return {};
    }
    bool dfs(vector<vector<int>>& obstacleGrid, int i, int j) {
        if (i >= 0 && i < row && j >=0 && j < col) {
            if  (obstacleGrid[i][j] == 0) {
                res.push_back({i,j});
                if (i == row - 1 && j == col - 1)
                    return true;
                if (dfs(obstacleGrid, i + 1, j))
                    return true;
                if (dfs(obstacleGrid, i, j + 1))
                    return true;
                res.pop_back();
            }
            obstacleGrid[i][j] = 1;
        }
        return false;
    }
}; */

class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> res;
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<int>> dp (row, vector<int>(col ,0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (obstacleGrid[i][j] == 1)    dp[i][j] = 0;
                else if (i == 0 && j == 0)      dp[i][j] = 1;
                else if (i == 0)                dp[i][j] = dp[i][j - 1];
                else if (j == 0)                dp[i][j] = dp[i - 1][j];
                else                            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        if (dp.back().back() == 0)
            return res;
        int i = row - 1, j = col - 1;
        res.push_back({i ,j});
        while (i + j > 0) {
            if (i >0 && dp[i - 1][j] > 0) {
                res.push_back({i - 1, j});
                i--;
            }
            else if (j > 0 && dp[i][j - 1] > 0) {
                res.push_back({i, j - 1});
                j--;
            }
        }
        reverse(res.begin(), res.end());
        return res; 
    }
};