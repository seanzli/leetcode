#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> hash; // num count;
        for (const auto& itr : nums) {
            if (hash.find(itr + k) != hash.end())
                res += hash[itr + k];
            if (hash.find(itr - k) != hash.end())
                res += hash[itr - k];
            ++hash[itr];
        }
        return res;
    }
};