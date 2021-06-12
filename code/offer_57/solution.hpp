#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> hash;
        for (int itr : nums) {
            if (hash.find(target - itr) == hash.end()) {
                hash.insert(itr);
            } else {
                return {itr, target - itr};
            }
        }
        return {};
    }
};