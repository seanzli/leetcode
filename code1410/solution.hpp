#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    int n = 0;
public:
    string entityParser(string text) {
        n = text.size();
        string out;
        for (int i = 0; i < text.size(); i++)
        {
            if (text[i]=='&')
                out += convert(text, i);
            else
                out += text[i];
        }
        return out;
    }

    char convert(string &text, int &i){
        if (n-i >= 3){
            string cur = text.substr(i+1, 3);
            if (cur == "gt;"){
                i = i + 3;
                return '>';
            } else if (cur == "lt;"){
                i = i + 3;
                return '<';
            }
        }
        if (n-i >= 4){
            string cur = text.substr(i+1, 4);
            if (cur == "amp;"){
                i = i + 4;
                return '&';
            }
        }
        if (n-i >= 5){
            string cur = text.substr(i+1, 5);
            if (cur == "quot;"){
                i = i + 5;
                return '\"';
            } else if (cur == "apos;"){
                i = i + 5;
                return '\'';
            }
        }
        if (n-i >= 6){
            string cur = text.substr(i+1, 6);
            if (cur == "frasl;"){
                i = i + 6;
                return '/';
            }
        }            
        return '&';
    }
};