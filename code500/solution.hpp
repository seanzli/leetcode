#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char, int> hash;
        vector<string> lines = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        
        // build hash map  <char, line-num>
        for (auto i = 0; i < 3; ++i) {
            for (char &ch : lines[i]) {
                hash[ch] = i;
                hash[ch - 'a' + 'A'] = i;
            }
        }

        vector<string> res;
        for (auto i = 0; i < words.size(); ++i) {
            int j = 0;
            const int line_num = hash[words[i][j]];
            for (/*j = 0*/ ; j < words[i].size(); ++j) {
                if (line_num != hash[words[i][j]])
                    break;
            }
            if (j == words[i].size())
                res.push_back(words[i]);
        }
        return res;
    }
};