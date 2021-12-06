#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int i = 0;
        for (/*int i = 0*/; i < s.size() && k > 0; ++i) {
            if (s[i] == ' ')
                --k;
        }
        if (i == s.size())
            return s;
        return s.substr(0, i - 1);
    }
};