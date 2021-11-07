#include <vector>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto& itr : ops) {
            m = min(m, itr[0]);
            n = min(n, itr[1]);
        }
        return m*n;
    }
};