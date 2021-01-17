#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    //recursion
/*     bool isInterleave(string s1, string s2, string s3) {
        int idx1=0, idx2=0, idx3=0;
        if ((s1.size() + s2.size())!= s3.size())
            return false;
        return check(s1, s2, s3, idx1, idx2, idx3);
    }

    bool check(string &s1, string &s2, string &s3, int idx1, int idx2 ,int idx3){
        if ((idx1==s1.size()) && (idx2==s2.size()) && (idx3==s3.size()))
            return true;
        if ((idx1>s1.size())||(idx2>s2.size()))
            return false;

        if ((s1[idx1]==s3[idx3]) && (check(s1,s2,s3,idx1+1,idx2, idx3+1)))
            return true;
        
        if ((s2[idx2]==s3[idx3]) && (check(s1,s2,s3,idx1,idx2+1, idx3+1)))
            return true;
        return false;
    } */

    //dp
    bool isInterleave(string s1, string s2, string s3) {
        if ((s1.size() + s2.size())!= s3.size())
            return false;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1));
        int idx;
        dp[0][0] = true;
        for (int i = 0; i <= s1.size(); i++)
        {
            for (int j = 0; j <= s2.size(); j++)
            {
                idx = i+j-1;
                if ((i==0)&&(j==0))
                    dp[0][0]= true;
                else if (i==0)
                    dp[0][j] = dp[0][j-1]&(s2[j-1]==s3[idx]);
                else if (j==0)
                    dp[i][0] = dp[i-1][0]&(s1[i-1]==s3[idx]);
                else if ((i==s1.size()) && (j==s2.size()))
                    dp[i][j] = dp[i-1][j]||dp[i][j-1];
                else
                    dp[i][j] = (dp[i-1][j]&(s1[i-1]==s3[idx])) || (dp[i][j-1]&(s2[j-1]==s3[idx]));
            }
        }
        return dp.back().back();
    }
};