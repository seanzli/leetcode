#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); i++) tmp ^= nums[i];
        int diff = tmp & (-tmp);
        int x = 0, y = 0;
        for (int num : nums) {
            if (num & diff) x ^= num;
            else y ^= num;
        }

        return {x, y};
    }
};