#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <math.h>

using namespace std;

class Solution {
public:
    int char2int(char i){
        return (i-'A'+1);
    }
    int titleToNumber(string s) {
        int out = 0;
        for (int i =0; i<s.size(); i++){
            out = out*26 + char2int(s[i]);
        }
        return out;
    }
};