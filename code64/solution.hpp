#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <math.h>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i==0 && j==0)
                    dp[0][0]=grid[0][0];
                else if (i==0)
                    dp[i][j] = dp[0][j-1] + grid[i][j];
                else if (j==0)
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                else
                    dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
            }
            
        }
        return dp.back().back();
    }
};