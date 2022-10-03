#include <string>

using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = false;
        for (int i = 0; i < s.size(); ++i) {
            if (!flag) {
                if (s[i] == '0')
                    flag = true;
            } else {
                if (s[i] == '1')
                    return false;
            }
        }
        return true;
    }
};