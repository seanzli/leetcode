#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int cur = sum / 4;
        if (sum % 4 != 0)
            return false;
        vector<int> acc(4, 0);
        sort(matchsticks.begin(), matchsticks.end());
        return dfs(matchsticks, acc, cur, 0);
    }
    bool dfs(vector<int>& match, vector<int>& acc, int& cur, int idx) {
        if (idx == match.size() && acc[0] == cur && acc[1] == cur && acc[2] == cur && acc[3] == cur)
            return true;

        for (int i = 0; i < 4; i++) {
            if (acc[i] + match[idx] <= cur) {
                acc[i] += match[idx];
                if (dfs(match, acc, cur, idx + 1))
                    return true;
                acc[i] -= match[idx];
            }
            if (acc[i] == 0 || acc[i] + match[idx] == cur)
                break;
        }
        return false;
    }
};