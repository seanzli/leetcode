#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    bool match(const string& word, const string& match) {
        unordered_map<char, char> hash;
        for (size_t i = 0; i < word.size(); ++i) {
            if (hash.find(word[i]) == hash.end()) {
                hash[word[i]] = match[i];
            } else if (hash[word[i]] != match[i]) {
                return false;
            }
        }
        return true;
    }

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (const string& itr : words) {
            if (match(itr, pattern) && match(pattern, itr))
                res.emplace_back(itr);
        }
        return res;
    }
};