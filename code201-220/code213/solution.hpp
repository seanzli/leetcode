#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }else if(n < 4){
            return (*max_element(nums.begin(),nums.end()));
        }
        int dp[n][2];               //边界情况：
        dp[0][0] = 0;               //没偷第0家时，偷到前0家的最大金额为0
        dp[0][1] = nums[0];         //有偷第0家时，偷到前0家的最大金额为nums[0]
        dp[1][1] = nums[0];         //有偷第0家时，偷到前1家的最大金额为nums[0]
        dp[1][0] = nums[1];         //没偷第0家时，偷到前1家的最大金额为nums[1]
        for(int i = 2; i < n; i++){
            if(i != n - 1){
                //如果不是偷最后一家，分有偷第0家和不偷第0家两条路线进行状态转移
                dp[i][0] = max(dp[i-1][0],dp[i-2][0] + nums[i]);
                dp[i][1] = max(dp[i-1][1],dp[i-2][1] + nums[i]);
            }else{
                //偷最后一家时,如果没偷过第0家，可以直接选择偷或者不偷
                dp[i][0] = max(dp[i-1][0],dp[i-2][0] + nums[i]);
                //如果已经偷过第0家，只能选择不偷
                dp[i][1] = dp[i-1][1];
            }
        }
        //返回两种偷法中金额较大的一种
        return max(dp[n-1][0],dp[n-1][1]);
    }
};