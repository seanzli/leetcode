#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class Solution {
public:
    string arrangeWords(string text) {
        regex re(" ");
        text[0] = text[0] + 'a' -'A';
        vector<string> m_vec(sregex_token_iterator(text.begin(), text.end(), re, -1), sregex_token_iterator());
        stable_sort(m_vec.begin(), m_vec.end(), [](string a, string b){return a.size()<b.size();});
        string out;
        for (string cur : m_vec)
            out += (cur+" ");
        out[0] = out[0] - 'a' +'A';
        return out.substr(0, out.size()-1);
    }
};