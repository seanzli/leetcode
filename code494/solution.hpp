#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int count = 0;
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        dfs(nums, sum, 0, S);
        return count;
    }

    void dfs(vector<int>& nums, int& sum, int level, int S) {
        if (level == nums.size()) {
            if (sum == S)
                count++;
            return;
        }
        sum += nums[level];
        dfs(nums, sum, level+1, S);
        sum -= nums[level];
        sum -= nums[level];
        dfs(nums, sum, level+1, S);
        sum += nums[level];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        if (S > sum) return 0; // 此时没有方案
        if ((S + sum) % 2 == 1) return 0; // 此时没有方案
        int bagSize = (S + sum) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bagSize; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
};