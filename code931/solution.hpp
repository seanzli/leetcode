#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp = matrix;
        int n = matrix.size();
        for (int row = 1; row < n; row++) {
            for (int col = 0; col < n; col++) {
                dp[row][col] = dp[row - 1][col] + matrix[row][col];
                if (col > 0)
                    dp[row][col] = min(dp[row - 1][col - 1] + matrix[row][col], dp[row][col]);
                if (col < n - 1)
                    dp[row][col] = min(dp[row - 1][col + 1] + matrix[row][col], dp[row][col]);
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};