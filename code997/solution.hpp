#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> count_trust(n + 1);
        for (auto& itr : trust) {
            --count_trust[itr[0]]; //trust people
            ++count_trust[itr[1]]; //
        }

        for (int i = 0; i < n; ++i) {
            if (count_trust[i] == n-1)
                return i;
        }
        return -1;
    }
};