#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto itr = word.find(ch);
        if (itr == word.npos) {
            return word;
        }
        reverse(word.begin(), word.begin() + itr + 1);
        return word;
    }
};