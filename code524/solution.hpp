#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        for (string& str : dictionary) {
            if (isSubstr(s, str)) {
                if (str.size() == res.size() && str < res)
                    res = str;
                else if (str.size() > res.size())
                    res = str;
            }
        }
        return res;
    }
    bool isSubstr(string& s, string& str) {
        unsigned idx2 = 0;
        for (unsigned idx1 = 0; idx2 < str.size() && idx1 < s.size(); ++idx1) {
            if (s[idx1] == str[idx2]) {
                ++idx2;
            }
        }
        if (idx2 == str.size())
            return true;
        return false;
    }
};