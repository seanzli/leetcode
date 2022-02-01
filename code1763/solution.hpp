#include <vector>
#include <string>

using namespace std;

class Solution {
    vector<int> lower = vector<int>(26, 0);
    vector<int> upper = vector<int>(26, 0);
public:
    string longestNiceSubstring(string s) {
        int res = -1;
        string r = "";
        for (int i = 0; i < s.size(); ++i) {
            add(s[i]);
            for (int j = i + 1; j < s.size(); ++j) {
                add(s[j]);
                if (same(lower, upper) && res < (j - i + 1)) {
                    res = j - i + 1;
                    r = s.substr(i, j - i + 1);
                }
            }
            for (int j = i + 1; j < s.size(); ++j)
                sub(s[j]);
            sub(s[i]);
        }
        return r;
    }

    bool same(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); ++i) {
            if ((a[i] > 0 && b[i] == 0) || (b[i] > 0 && a[i] == 0))
                return false;
        }
        return true;
    }
    void add(const char c) {
        if (c > 'Z') // lower
            ++lower[c - 'a'];
        else
            ++upper[c - 'A'];
    }

    void sub(const char c) {
        if (c > 'Z') // lower
            --lower[c - 'a'];
        else
            --upper[c - 'A'];
    }
};