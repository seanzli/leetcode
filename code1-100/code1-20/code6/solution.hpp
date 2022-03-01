#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    string convert(string s, int numRows) {
//        string out;
//        char *p = (char*)s.c_str();
//
//        if (s.size()<2)
//            return s;
//        if (numRows <2)
//            return s;
//
//        int idx = 0, cur_idx = 0;
//        int n = s.size()/(numRows*2-2)+1;
//        for (int i = 0; i < n+1; i++)
//        {
//            cur_idx = i*numRows*2-i*2;
//            if (cur_idx < s.size())
//            {
//                out.insert(out.end(),p[cur_idx]);
//            }
//        }
//
//        for (int i = 1; i < numRows-1; i++)
//        {
//            if (i<s.size())
//                out.insert(out.end(),p[i]);
//            for (int j = 1; j < n+1; j++)
//            {
//                cur_idx = j*numRows*2-j*2;
//                if (cur_idx-i<s.size())
//                {
//                    out.insert(out.end(), p[cur_idx-i]);
//                }
//                if (cur_idx+i<s.size())
//                {
//                    out.insert(out.end(), p[cur_idx+i]);
//                }
//            }
//        }
//
//        for (int i = 0; i < n+1; i++)
//        {
//            cur_idx = i*numRows*2-i*2+numRows-1;
//            if (cur_idx < s.size())
//            {
//                out.insert(out.end(),p[cur_idx]);
//                idx++;
//            }
//        }
//        return out;
//    }
//};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> sub(numRows, "");
        int idx = 0, dif = 1;
        for (int i = 0; i < s.size(); ++i) {
            sub[idx].push_back(s[i]);
            if (idx == numRows - 1) {
                dif = -1;
            } else if (idx == 0) {
                dif = 1;
            }
            idx += dif;
        }
        string res = "";
        for (int i = 0; i < numRows; ++i) {
            res += sub[i];
        }
        return res;
    }
};