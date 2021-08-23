#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     int getMaximumGenerated(int n) {
//         vector<int> dp(n+1, 0);
//         dp[1] = 1;
//         int i = 1;
//         while (2*i < n+1 ){
//             dp[2*i] = dp[i];
//             if (2*i+1 < n+1)
//                 dp[2*i+1] = dp[i] + dp[i+1];
//             i++;
//         }
//         return *max_element(dp.begin(), dp.end());
//     }
// };

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 1)
            return n;
        vector<int> dp(n + 1, 0);
        dp[0] = 0; dp[1] = 1;
        int i = 1;
        while (2*i < n+1 ){
            dp[2*i] = dp[i];
            if (2*i+1 < n+1)
                dp[2*i+1] = dp[i] + dp[i+1];
            i++;
        }
        return *max_element(dp.begin(), dp.end());
    }
};