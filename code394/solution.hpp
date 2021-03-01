#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res = "";
        int pred = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                pred *= 10;
                pred += (s[i] - '0');
            } else if (s[i] == '[') {
                string cur = decode(s, i);
                for ( ; pred > 0; pred--) {
                    res += cur;
                }
            } else {
                res += s[i];
            }
        }
        return res;
    }
    string decode(string s, int& i) {
        string res = "";
        i = i + 1;
        int pred = 0;
        for ( ; i < s.size(); i++) {
            if (s[i] == ']')
                return res;
            else if (s[i] >= '0' && s[i] <= '9') {
                pred *= 10;
                pred += (s[i] - '0');
            } else if (s[i] == '[') {
                string cur = decode(s, i);
                for ( ; pred > 0; pred--) {
                    res += cur;
                }
            } else {
                res += s[i];
            }
        }
        return res;
    }
};