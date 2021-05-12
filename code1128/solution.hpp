#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        sort(dominoes.begin(), dominoes.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] > a[1])
                swap(a[0], a[1]);
            if (b[0] > b[1])
                swap(b[0], b[1]);
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> res;
        int out = 0;
        int i = 0;
        for (auto itr : dominoes) {
            for (i = 0; i < res.size(); i++) {
                if (res[i][0] == itr[0] && res[i][1] == itr[1]) {
                    out++;
                    break;
                }
            }
            if (i == res.size())
                res.push_back(itr);
        }
        return out;
    }
};