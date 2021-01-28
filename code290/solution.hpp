#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <regex>

using namespace std;

/* class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string, char> str2ch;
        unordered_map<char, string> ch2str;
        int m = str.length();
        int i = 0;
        for (auto ch : pattern) {
            if (i >= m) {
                return false;
            }
            int j = i;
            while (j < m && str[j] != ' ') j++;
            const string &tmp = str.substr(i, j - i);
            if (str2ch.count(tmp) && str2ch[tmp] != ch) {
                return false;
            }
            if (ch2str.count(ch) && ch2str[ch] != tmp) {
                return false;
            }
            str2ch[tmp] = ch;
            ch2str[ch] = tmp;
            i = j + 1;
        }
        return i >= m;
    }
}; */

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> char2str;
        unordered_map<string, char> str2char;

        std::regex re(" ");
        vector<string> sub(sregex_token_iterator(s.begin(), s.end(), re, -1), sregex_token_iterator());
        if (sub.size() != pattern.size())
            return false;

        for (int i = 0; i < sub.size(); i++)
        {
            if (char2str.find(pattern[i])==char2str.end()){
                char2str[pattern[i]] = sub[i];
            }
            if (str2char.find(sub[i])==str2char.end()){
                str2char[sub[i]] = pattern[i];
            }
            if (char2str[pattern[i]].compare(sub[i])!=0)
                return false;
            if (str2char[sub[i]] != pattern[i])
                return false;
        }
        return true;
    }
};