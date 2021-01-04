#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size()<1)
            return 0;
        if (haystack.size()<needle.size())
            return -1;
        
        int j,i;
        for (i = 0; i < haystack.size()-needle.size()+1; i++)
        {
            if (haystack[i] == needle[0])
            {
                for (j = 1; j < needle.size(); j++)
                {
                    if(haystack[i+j] != needle[j])
                        break;
                }
                if (j==needle.size())
                    return i;
            }
        }
        return -1;
    }
};