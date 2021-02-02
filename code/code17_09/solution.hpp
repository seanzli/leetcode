#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> dp(k,1);
        int p3 = 0, p5=0, p7=0;
        for (int i = 1; i < k; i++){
            dp[i] = min(dp[p3] * 3, min(dp[p5] * 5, dp[p7] * 7));
            // 将该数字对应的指针向前移动一步。
            if( dp[i] == dp[p3] * 3 ) p3++;
            if( dp[i] == dp[p5] * 5 ) p5++;
            if( dp[i] == dp[p7] * 7 ) p7++; 
        }
        return dp[k-1];
    }
};