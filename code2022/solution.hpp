#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        if (original.size() != m * n)
            return res;
        for (int i = 0; i < m; ++i) {
            res.emplace_back(original.begin() + n * i, original.begin() + n * i + n);
        }
        return res;
    }
};