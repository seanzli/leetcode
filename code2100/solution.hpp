#include <vector>

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> g(n, 0); // 1 : increase, 0 = no change, -1 = decrease
        for (int i = 1; i < n; ++i) {
            if (security[i] == security[i - 1])
                continue;
            g[i] = security[i] > security[i - 1] ? 1 : -1;
        }
        vector<int> increase(n + 1, 0), decrease(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            increase[i] = increase[i - 1] + (g[i - 1] == 1 ? 1 : 0); // increase count
            decrease[i] = decrease[i - 1] + (g[i - 1] == -1 ? 1 : 0); // decrease count
        }
        vector<int> res;
        for (int i = time; i < n - time; ++i) {
            int c1 = increase[i + 1] - increase[i + 1 - time]; // increase count in [i - time , i]
            int c2 = decrease[i + 1 + time] - decrease[i + 1]; // decrease count in [i, i + time];
            if (c1 == 0 && c2 == 0)
                res.push_back(i);
        }
        return res;
    }
};