#include <string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        return allCapital(word) || noCapital(word) || firstCapital(word);
    }

    bool allCapital(const string& str) {
        for (const char& itr : str) {
            if (islower(itr))
                return false;
        }
        return true;
    }

    bool noCapital(const string& str) {
        for (const char& itr : str) {
            if (isupper(itr))
                return false;
        }
        return true;
    }

    bool firstCapital(const string& str) {
        return isupper(str[0]) && noCapital(str.substr(1));
    }
};