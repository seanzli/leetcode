#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <numeric>
#include <queue>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     int findPaths(int m, int n, int N, int i, int j) {
//         if (N == 0)
//             return 0;
//         long dp[N][m + 2][n + 2];
//         memset(dp, 0, sizeof(dp));
//         dp[0][i + 1][j + 1] = 1;
//         long int res = 0;
//         if (i == 0)res++;
//         if (i == m - 1)res++;
//         if (j == 0)res++;
//         if (j == n - 1)res++;

//         for (int t = 1; t < N; t++) {
//             for (int mi = 1; mi <= m; mi++) {
//                 for (int ni = 1; ni <= n; ni++) {
//                     dp[t][mi][ni] = dp[t - 1][mi - 1][ni] + dp[t - 1][mi + 1][ni]
//                                     + dp[t - 1][mi][ni - 1] + dp[t - 1][mi][ni + 1];
//                     dp[t][mi][ni] %= 1000000007;
//                     if (mi == 1)res += dp[t][mi][ni];
//                     if (mi == m)res += dp[t][mi][ni];
//                     if (ni == 1)res += dp[t][mi][ni];
//                     if (ni == n)res += dp[t][mi][ni];
//                     res %= 1000000007;
//                 }
//             }
//         }
//         return int(res);
//     }
// };

class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int outCounts = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[startRow][startColumn] = 1;
        for (int i = 0; i < maxMove; i++) {
            vector<vector<int>> dpNew(m, vector<int>(n));
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    int count = dp[j][k];
                    if (count > 0) {
                        for (auto& direction : directions) {
                            int j1 = j + direction[0], k1 = k + direction[1];
                            if (j1 >= 0 && j1 < m && k1 >= 0 && k1 < n) {
                                dpNew[j1][k1] = (dpNew[j1][k1] + count) % MOD;
                            } else {
                                outCounts = (outCounts + count) % MOD;
                            }
                        }
                    }
                }
            }
            dp = dpNew;
        }
        return outCounts;
    }
};