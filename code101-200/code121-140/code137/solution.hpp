#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash; // num count;
        for (auto itr : nums) {
            hash[itr]++;
        }
        for (auto itr : hash) {
            if (itr.second == 1)
                return itr.first;
        }
        return 0;
    }
}; */

/* class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 2)
            return nums[0];
        int i = 0;
        while ((i+2) < nums.size()){
            if ((nums[i]!=nums[i+1]) || (nums[i+1]!=nums[i+2]))
                break;
            i = i + 3;
        }
        if (i > nums.size())
            return nums.back();
        return nums[i];
    }
}; */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = ones ^ num & ~twos;
            twos = twos ^ num & ~ones;
        }
        return ones;
    }
};