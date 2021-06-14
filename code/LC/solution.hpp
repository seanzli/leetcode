#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;

        sort(nums.begin(), nums.end());

        int len = nums.size();
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            if (nums[i] > 0) return res;
            int left = i + 1, right = len - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0) ++left;
                else if (sum > 0) --right;
                else {
                    vector<int> tmp {nums[i], nums[left++], nums[right--]}; 
                    res.push_back(tmp);
                    while(left < right && nums[left] == nums[left - 1]) ++left;
                    while(left < right && nums[right] == nums[right + 1]) --right;  
                }
            }
        }
        return res;
    }
};