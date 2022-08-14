#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n_1 = 0;
        for (const char& c : s) {
            if (c == '1')
                ++n_1;
        }
        int res = 0;
        int left_1 = 0, left_0 = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0')
                ++left_0;
            else
                ++left_1;
            res = max(res, left_0 + n_1 - left_1);
        }
        return res;
    }
};