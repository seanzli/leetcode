#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> hash;
        for (const auto& cur : target)
            ++hash[cur];
        for (const auto& cur : arr)
            --hash[cur];
        for (auto itr : hash) {
            if (itr.second != 0)
                return false;
        }
        return true;
    }
};