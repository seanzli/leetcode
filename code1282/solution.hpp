#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < groupSizes.size(); ++i) {
            hash[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> res;
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
            int num = itr->first;
            for (auto i = itr->second.begin(); i != itr->second.end(); i = next(i, num)) {
                res.push_back(vector<int>(i, next(i, num)));
            }
        }
        return res;
    }
};