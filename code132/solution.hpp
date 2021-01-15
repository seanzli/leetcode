#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        vector<int> dp(len, 0);
        for (int i = 0; i < len; i++)
            dp[i]=i;
        
        vector<vector<bool>> check(len, vector<bool>(len, false));
        for(int right=0;right<len;right++){
            for(int left=0;left<=right;left++){
                if(s[left]==s[right] && (right-left<=2 || check[left+1][right-1])){
                    check[left][right]=true;
                }
            }
        }

        //dp[i] = min(dp[j] + 1 if s[j + 1: i] 是回文 for j in range(i))
        for (int i = 0; i < s.size(); i++)
        {
            if (check[0][i])
                dp[i]=0;
            else
            {
                for (int j = i-1; j >= 0; j--)
                {
                    if (check[j+1][i])
                        dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp.back();
    }
};