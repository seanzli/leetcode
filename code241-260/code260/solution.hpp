#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         unordered_set<int> hash;
//         for (int i : nums){
//             if (!hash.insert(i).second)
//                 hash.erase(i);
//         }
//         return vector<int>(hash.begin(), hash.end());
//     }
// };

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int& itr : nums) {
            hash[itr]++;
        }
        vector<int> res{};
        for (auto itr = hash.begin(); itr != hash.end(); ++itr) {
            if (itr->second == 1)
                res.push_back(itr->first);
        }
        return res;
    }
};