#include <vector>
#include <unordered_set>

using namespace std;

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         unordered_set<int> hash;
//         for (int i = 0; i <= nums.size(); ++i) {
//             hash.insert(i);
//         }
//         for (auto& i : nums)
//             hash.erase(i);

//         return *hash.begin();
//     }
// };

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= i;
            res ^= nums[i];
        }
        return res ^ nums.size();
    }
};