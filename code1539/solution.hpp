#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cur = 1, idx = 0;
        while (k && idx < arr.size()) {
            if (arr[idx] == cur) {
                idx++;
                cur++;
                
            } else if (arr[idx] < cur) {
                idx++;
            } else {
                k--;
                cur++;
            }
        }
        cur += (k - 1);
        return cur;
    }
};