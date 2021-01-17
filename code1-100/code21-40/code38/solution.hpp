#include <vector>
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    string countAndSaySub(string s){
        char p = s[0], cur;
        int count = 1;
        string out = "";
        for (int i = 1; i < s.size(); i++)
        {
            if (p == s[i])
                count++;
            else
            {
                cur = count + '0';
                out = out + cur + p;
                p = s[i];
                count = 1;
            }
        }
        cur = count + '0';
        out = out + cur + p;
        return out;
    }
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++)
            s = countAndSaySub(s);
        return s;
    }
};