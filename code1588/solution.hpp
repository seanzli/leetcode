/*
 * @Description: 
 * @Author: Sean
 * @Date: 2021-08-29 09:51:41
 * @LastEditTime: 2021-08-29 09:57:28
 * @LastEditors: Sean
 * @Reference: 
 */

#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;

        for (int left = 0; left < arr.size(); ++left) { // start
            int cur = 0;
            for (int right = left; right < arr.size(); ++right) {
                cur += arr[right];
                if ((right - left) % 2 == 0)
                    res += cur;
            }
        }
        return res;
    }
};