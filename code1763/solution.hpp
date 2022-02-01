#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int res = -1;
        string r = "";
        for (int i = 0; i < s.size(); ++i) {
            vector<bool> lower(26, false);
            vector<bool> upper(26, false);
            s[i] > 'Z' ? lower[s[i] - 'a'] = true : upper[s[i] - 'A'] = true;
            for (int j = i + 1; j < s.size(); ++j) {
                s[j] > 'Z' ? lower[s[j] - 'a'] = true : upper[s[j] - 'A'] = true;
                if ((lower == upper) && res < (j - i + 1)) {
                    res = j - i + 1;
                    r = s.substr(i, j - i + 1);
                }
            }
        }
        return r;
    }
};