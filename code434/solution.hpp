#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int res = 0;
        int cur = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                if (cur > 0) {
                    ++res;
                    cur = 0;
                }
            } else {
                ++cur;
            }
        }
        if (cur)
            ++res;

        return res;
    }
};