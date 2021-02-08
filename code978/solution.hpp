#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size()==1) return 1;
        vector<int> dp(arr.size(), 1);
        dp[0] = 1;
        if (arr[0] > arr[1] || arr[0] < arr[1])
            dp[1] = 2;

        for (int i=2; i<arr.size(); i++){
            if (arr[i] > arr[i-1]){
                if (arr[i-1] < arr[i-2])
                    dp[i] = dp[i-1] + 1;
                else
                    dp[i] = 2;
            } else if (arr[i] < arr[i-1]) {
                if (arr[i-1] > arr[i-2])
                    dp[i] = dp[i-1] + 1;
                else
                    dp[i] = 2;
            } else {
                dp[i] = 1;
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};