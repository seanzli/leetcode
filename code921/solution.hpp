#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int cur = 0;
        int res = 0;
        for (const auto& c : s) {
            if (c == '(')
                ++cur;
            else {
                --cur;
                if (cur < 0) {
                    ++res;
                    cur = 0;
                }
            }
        }
        res += cur;
        return res;
    }
};