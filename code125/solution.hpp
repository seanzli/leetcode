#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <algorithm>
#include <regex>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        if (s.size()==0)
            return true;

        int start = 0, end = s.size()-1;
        while (start<end)
        {
            if (!isalnum(s[start])) 
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }
            if (tolower(s[start])!=tolower(s[end]))
                return false;
            else{
                start++;
                end--;
            }
        }
        return true;        
    }
};