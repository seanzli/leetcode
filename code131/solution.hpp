#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> out;
    vector<string> cur;
    vector<vector<string>> partition(string s) {
        getPartition(s);
        return out;
    }
    void getPartition(string s){
        string cur_string;
        for (int i = 1; i <= s.size(); i++)
        {
            cur_string = s.substr(0,i);
            if (isPartition(cur_string))
            {
                cur.push_back(cur_string);
                if (i==s.size())
                    out.push_back(cur);
                else
                    getPartition(s.substr(i));
                cur.pop_back();
            }
        }
    }
    bool isPartition(string &s){
        int start = 0, end = s.size()-1;
        while (start<end){
            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};