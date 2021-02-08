#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>

using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        regex re(" ");
        int idx = 0;
        for ( ; idx<s.size(); idx++){
            if (s[idx] != ' ')
                break;
        }
        s.substr(idx);
        vector<string> words(sregex_token_iterator(s.begin(), s.end(), re, -1), sregex_token_iterator());
        vector<int> length;
        for (auto i : words)
            length.push_back(i.size());
        vector<string> out(*max_element(length.begin(), length.end()), "");
        for (int i = 0; i < out.size(); i++)
        {
            for (int j = 0; j< words.size(); j++){
                if (words[j].size() > i)
                    out[i] = out[i] + words[j][i];
                else
                    out[i] = out[i] + " ";
            }
            int idx = out[i].size()-1;
            for (; idx>=0; idx--){
                if (out[i][idx]!=' ')
                    break;
            }
            out[i] = out[i].substr(0,idx+1);
        }
        return out;
    }
};