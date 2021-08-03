/*
 * @Description: 
 * @Author: Sean
 * @Date: 2021-08-03 20:15:01
 * @LastEditTime: 2021-08-03 20:18:08
 * @LastEditors: Sean
 * @Reference: 
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        int left, right;
        for (left = 0; left < nums.size(); ++left) {
            if (nums[left] != copy[left])
                break;
        }
        if (left == nums.size())
            return 0;
        for (right = nums.size() - 1; right >= left; --right) {
            if (nums[right] != copy[right])
                break;
        }
        return right - left + 1;
    }
};