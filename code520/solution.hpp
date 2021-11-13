#include <string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        return allCapital(word) || noCapital(word) || firstCapital(word);
    }

    bool allCapital(const string& str) {
        for (const char& itr : str) {
            if (!isCapital(itr))
                return false;
        }
        return true;
    }

    bool noCapital(const string& str) {
        for (const char& itr : str) {
            if (isCapital(itr))
                return false;
        }
        return true;
    }

    bool firstCapital(const string& str) {
        return isCapital(str[0]) && noCapital(str.substr(1));
    }

    bool isCapital(const char& c) {
        return (c <= 'Z' && c >= 'A');
    }
};