#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int cur;
        for (int i = 1; i < prices.size(); i++)
        {
            cur = prices[i]-prices[i-1];
            if (cur > 0)
                max_profit += cur;
        }
        return max_profit;
    }
};