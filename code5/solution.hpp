#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        char *p = (char*)s.c_str();
        int idx = 0;
        string out = "";
        if (s.size()<2)
            return s;

        for (int i = 0; i < s.size()-out.size(); i++)
        {
            for (int j = s.size(); j >i ; j--)
            {
                if (out.size()<=(j-i+1) && isPalindroms(s.substr(i,j-i+1)))
                {
                    out = s.substr(i,j-i+1);
                }
            }
        }
        return out;
    }
    bool isPalindroms(string s){
        if (s.size() < 2)
            return true;
        char *p = (char*)s.c_str();
        int idx1, idx2;
        if ((s.size())==(s.size())/2*2) //even num
        {
            idx1 = (s.size())/2-1;
            idx2 = (s.size())/2;
        }
        else //odd num
        {
            idx1 = (s.size())/2-1;
            idx2 = (s.size())/2+1;
        }
        while (idx1>=0){
            if (p[idx1]!=p[idx2])
                return false;
            idx1--;
            idx2++;
        }
        return true;
    }
};