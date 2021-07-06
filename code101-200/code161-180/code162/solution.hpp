#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return search(nums, 0, nums.size() - 1);
    }
    int search(vector<int>& nums, int left, int right) {
        if (left == right)
            return left;
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1])
            return search(nums, left, mid);
        return search(nums, mid + 1, right);
    }
};