#include <vector>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0];
        int cur = nums[0];
        for (size_t right = 1; right < nums.size(); ++right) {
            if (nums[right] > nums[right - 1])
                cur += nums[right];
            else {
                if (cur > res)
                    res = cur;
                cur = nums[right];
            }
        }
        return cur > res ? cur : res;
    }
};