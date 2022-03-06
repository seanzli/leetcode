#include <vector>

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> g(n, 0);
        for (int i = 1; i < n; ++i) {
            if (security[i] == security[i - 1])
                continue;
            g[i] = security[i] > security[i - 1] ? 1 : -1;
        }
        vector<int> left(n + 1, 0), right(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            left[i] = left[i - 1] + (g[i - 1] == 1 ? 1 : 0);
            right[i] = right[i - 1] + (g[i - 1] == -1 ? 1 : 0);
        }
        vector<int> res;
        for (int i = time; i < n - time; ++i) {
            int c1 = left[i + 1] - left[i + 1 - time];
            int c2 = right[i + 1 + time] - right[i + 1];
            if (c1 == 0 && c2 == 0)
                res.push_back(i);
        }
        return res;
    }
};