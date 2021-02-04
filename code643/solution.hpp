#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0;
        double max_mean = 0.0;
        for (int i = 0; i < k; i++){
            sum += nums[i];
        }
        max_mean = sum / k;
        for (int i = k; i < nums.size(); i++)
        {
            sum -= nums[i-k];
            sum += nums[i];
            max_mean = max(max_mean, sum/k);
        }
        return max_mean;
    }
};