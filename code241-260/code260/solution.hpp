#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> hash;
        for (int i : nums){
            if (!hash.insert(i).second)
                hash.erase(i);
        }
        return vector<int>(hash.begin(), hash.end());
    }
};