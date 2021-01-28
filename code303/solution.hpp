#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i : nums)
        {
            sums.push_back(sum);
            sum = sum + i;
        }
        sums.push_back(sum);

    }
    
    int sumRange(int i, int j) {
        return sums[j+1]-sums[i];
    }
};
