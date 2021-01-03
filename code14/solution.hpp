#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()<1)
            return "";
        
        string out = strs.at(0);
        int i =1;
        for (i = 1; i < strs.size(); i++)
        {
            int j = out.size();
            for (; j >0; j--)
            {
                out = out.substr(0,j);
                if (strs[i].find(out)==0)
                    break;           
            }
            if (j==0)
                return "";
        }
        return out;
    }
};