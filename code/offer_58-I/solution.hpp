#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> cur;
        string t = "";
        for (char i : s) {
            if (i == ' ') {
                if (t.size())
                    cur.push_back(t);
                t = "";
            } else {
                t += i;
            }
        }
        if (t.size())
            cur.push_back(t);
        reverse(cur.begin(), cur.end());
        string res = "";
        for (string c : cur) {
            res += (c + " ");
        }
        if (res.size())
            res.pop_back();
        return res;
    }
};