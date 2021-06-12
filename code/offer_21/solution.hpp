#include <vector>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] % 2 == 0) { // even number
                swap(nums[left], nums[right]);
                right--;
            } else {
                left++;
            }
        }
        return nums;
    }
};