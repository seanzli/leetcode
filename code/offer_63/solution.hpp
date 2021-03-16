#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
            
        int min_value = prices[0];
        int max_value = 0;
        for (int i = 1; i < prices.size(); i++) {
            max_value = max(max_value, max(0, prices[i] - min_value));
            min_value = min(min_value, prices[i]);
        }
        return max_value;
    }
};