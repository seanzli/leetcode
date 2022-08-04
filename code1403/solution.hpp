#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), [](const int& a, const int& b) {return a > b;});
        int cur = 0, i = 0;
        for (/*already init*/; i < nums.size(); ++i)
        {
            cur += nums[i];
            if (cur > sum - cur)
                break;
        }
        return vector<int>(nums.begin(), nums.begin() + i);
    }
};