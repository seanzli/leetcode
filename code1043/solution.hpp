#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int len = arr.size();
        vector<int> dp(len);
        for (int i = 0; i < len; i++) {
            int maxNum = 0;
            for (int j = i; j > i - k && j >= 0; j--) { // j从i出发往前取k个
                maxNum = max(maxNum, arr[j]);
                // 状态转移方程  dp[i] = max(dp[i], dp[j-1]+maxNum*(i-j+1)), 注意处理一下j=0时的临界条件
                dp[i] = max(dp[i], j != 0 ? dp[j - 1] + maxNum * (i - j + 1) : maxNum * (i - j + 1));
            }
        }
        return dp[len - 1];
    }
};