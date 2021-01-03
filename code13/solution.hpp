#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int char2num(char in){
        switch(in){
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
            default :return 0;
        }
    }

    int romanToInt(string s) {
        char *p = (char*)s.c_str();
        if (s.size()<1)
            return 0;

        int out = 0, cur_num = 0, prev_num = 0;
        int idx = s.size()-1;
        for (int idx = s.size()-1; idx >=0 ; idx--)
        {
            cur_num = char2num(p[idx]);
            if (prev_num>cur_num)
                out -= cur_num;
            else
                out += cur_num;
            prev_num = cur_num;
        }
        return out;
    }
};