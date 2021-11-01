#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> set;
        for (auto &itr : candyType)
            set.insert(itr);
        return min(candyType.size() / 2, set.size());
    }
};