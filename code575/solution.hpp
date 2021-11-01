#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     int distributeCandies(vector<int>& candyType) {
//         unordered_set<int> set;
//         for (auto &itr : candyType)
//             set.insert(itr);
//         return min(candyType.size() / 2, set.size());
//     }
// };

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        std::sort(candyType.begin(), candyType.end());
        auto idx = std::unique(candyType.begin(), candyType.end());
        return min(candyType.size() / 2, static_cast<size_t>(std::distance(candyType.begin(), idx)));
    }
};
