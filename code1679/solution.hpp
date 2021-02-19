#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int idx = nums.size() - 1;
        for ( ; idx >= 0; idx--) {
            if (nums[idx] <= k)
                break;
        }
        if (idx == 0)
            return 0;
        
        int left = 0, right = idx, count = 0;
        while (left < right) {
            if (nums[left] + nums[right] > k) {
                right--;
            } else if (nums[left] + nums[right] < k) {
                left++;
            } else {
                count++;
                left++;
                right--;
            }
        }
        return count;
    }
};