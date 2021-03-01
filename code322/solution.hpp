#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> num(n, 0);
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i - coins[j] >= 0)
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};