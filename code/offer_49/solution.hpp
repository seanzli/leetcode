#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        if (n == 1)
            return 1;
        int idx2 = 0, idx3 = 0, idx5 = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[idx2] * 2, dp[idx3] * 3);
            dp[i] = min(dp[i], dp[idx5] * 5);
            
            if (dp[i] == dp[idx2] * 2)
                idx2++;
            else if (dp[i] == dp[idx3] * 3)
                idx3++;
            else
                idx5++;
        }
        return dp.back();
    }
};