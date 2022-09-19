#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> hash; // num -> count;
        for (const auto& itr : nums) {
            ++hash[itr];
        }
        vector<pair<int, int>> vec;
        for (auto itr : hash) {
            vec.push_back(make_pair(itr.first, itr.second));
        }
        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        });
        vector<int> res;
        for (auto itr : vec) {
            for (int i = 0; i < itr.second; i++)
                res.push_back(itr.first);
        }
        return res;
    }
};