#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        size_t idx1 = 0, idx2 = 0;
        while (idx1 < word1.size() && idx2 < word2.size()) {
            res += word1[idx1++];
            res += word2[idx2++];
        }
        while (idx1 < word1.size())
            res += word1[idx1++];
        while (idx2 < word2.size())
            res += word2[idx2++];
        return res;
    }
};