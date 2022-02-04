#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int, int> hash; // square , count;
        for (const auto& itr : rectangles)
            ++hash[std::min(itr[0], itr[1])];

        return hash.rbegin()->second;
    }
};