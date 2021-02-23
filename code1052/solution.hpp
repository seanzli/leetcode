#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int res = 0;
        int max_res = 0;
        int n = customers.size();
        for (int i = 0; i < n; i++) {
            res += (customers[i]*(1 - grumpy[i]));
        }
        int left = 0, right = X;
        for (int i = 0; i < right; i++) {
            if (grumpy[i] == 1)
                res += customers[i];
        }
        max_res = res;
        for ( right; right < n; right++) {
            if (grumpy[left] == 1) {
                res -= customers[left];
            }
            left++;
            if (grumpy[right] == 1)
                res += customers[right];
            max_res = max(max_res, res);
        }
        return max_res;
    }
};