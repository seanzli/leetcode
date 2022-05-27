#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int idx1 = -1, idx2 = -1;
        int size = words.size();
        int res = size;
        for (int i = 0; i < size; ++i) {
            if (words[i] == word1)
                idx1 = i;
            if (words[i] == word2)
                idx2 = i;
            if (idx1 >= 0 && idx2 >= 0)
                res = min(res, abs(idx1 - idx2));
        }
        return res;
    }
};