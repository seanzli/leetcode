#include <string>
#include <vector>
#include <unordered_set>
#include <regex>

using namespace std;

class Solution {
    unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
    string toGoatLatin(string sentence) {
        string tail = "a";
        string vowel_tail = "ma";
        vector<string> words = split(sentence);
        string res = "";
        for (auto& str : words) {
            if (str.empty())
                continue;
            if (vowel.count(str[0]) == 0) {
                head2tail(str);
            }
            str += vowel_tail;
            res += str + tail + " ";
            tail += "a";
        }
        if (res.empty())
            return res;
        return res.substr(0, res.size() - 1);
    }

    vector<string> split(const string& sentence) {
        regex re(" ");
        return vector<string>(
                sregex_token_iterator(sentence.begin(), sentence.end(), re, -1),
                sregex_token_iterator()
                );
    }

    void head2tail(string& str) {
        string head = str.substr(0,1);
        string tail = str.substr(1);
        str = tail + head;
    }
};