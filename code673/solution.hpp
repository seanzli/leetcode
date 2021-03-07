#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 1)); // length - count;
        int max_length = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    if (dp[i][0] == dp[j][0] + 1) {
                        dp[i][1] +=  dp[j][1];
                    } else if (dp[i][0] < dp[j][0] + 1) {
                        dp[i][0] = dp[j][0] + 1;
                        dp[i][1] =  dp[j][1];
                    }
                }
                max_length = max(max_length, dp[i][0]);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i][0] == max_length)
                count += dp[i][1];
        }
        return count;
    }
};