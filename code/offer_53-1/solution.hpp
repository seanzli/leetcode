#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
                break;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (nums[mid] != target)
            return 0;
        for (left = mid - 1; left >= 0 && nums[left] == target ; left--) {}
        for (right = mid + 1; right < nums.size() && nums[right] == target; right++) {}

        return right - left - 1;
    }
};