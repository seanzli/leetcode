#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++){
            //寻找最大因子(这里有点贪心的味道在里面, 你品,你细品~)
            for(int k = i / 2; k > 0; k--){
                if(i % k == 0){
                    dp[i] = dp[k] + 1 + (i - k) / k; //状态转移方程: dp[i] = 数字i的最大因子次数 加 复制一次 加 Paste次数
                    break;
                }
            }
        }
        return dp[n];

    }
};