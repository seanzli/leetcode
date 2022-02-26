#include <vector>

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_idx = 0;
        int max_dis = -1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[min_idx] > max_dis)
                max_dis = nums[i] - nums[min_idx];
            if (nums[i] < nums[min_idx])
                min_idx = i;
        }
        return max_dis == 0 ? -1 : max_dis;
    }
};