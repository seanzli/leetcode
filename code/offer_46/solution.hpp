#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        if (n==1)
            return dp.back();
        dp[1] = 1;
        if ((s[0] == '1') || (s[0] == '2' && s[1]<'6'))
            dp[1] = 2;
        
        for (int i = 2; i < n; i++)
        {
            if ((s[i-1] == '1') || (s[i-1] == '2' && s[i]<'6'))
                dp[i] = dp[i-1]+ dp[i-2];
            else
                dp[i] = dp[i-1];
            
        }
        return dp.back();
    }
};