#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <math.h>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        vector<string> split_s;
        s = deleteSpace(s);
        SplitString(s, split_s, "e");
        if (split_s.size()>2)
            return false;
        
        if (!isNumberWithoutE(split_s[0], false))
            return false;
        if (split_s.size()==2)
        {
            if (!isNumberWithoutE(split_s[1], true))
                return false;
        }
        return true;
    }
    bool isNumberWithoutE(string s, bool got_dot){
        if (s.size()<1)
            return false;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (((s[i]=='+')||(s[i]=='-')) && (i!=0))
                return false;
            else if (s[i]=='.')
            {
                if (got_dot)
                    return false;
                got_dot = true;
            }
            else if ((s[i]>='0') && (s[i]<='9'))
                continue;
            else
                return false;
        }
        return true;
    }
    string deleteSpace(string &s){
        vector<string> out;
        SplitString(s, out, " ");
        s.clear(); 
        for (int i = 0; i < out.size(); i++)
            s+=out[i];
        return s;
    }
    void SplitString(const string& s, vector<std::string>& v, std::string c)
    {
        std::string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(std::string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2-pos1));
        
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
    }
};