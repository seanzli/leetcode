#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = left + (right - left) / 2;
            int need = 1, cur = 0;
            for (auto itr : weights) {
                if (cur + itr > mid) {
                    need++;
                    cur = 0;
                }
                cur += itr;
            }
            if (need <= D)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};