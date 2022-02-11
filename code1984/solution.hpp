#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1)
            return 0;
        sort(nums.begin(), nums.end());
        int res = nums.back() - nums[0];
        for (int i = 0; i + k - 1 < nums.size(); ++i) {
            res = min(res, nums[i + k - 1] - nums[i]);
        }
        return res;
    }
};