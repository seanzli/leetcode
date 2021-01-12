#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int sum = 0;
    string cur_s = "";
    int numDecodings(string s) {
        int length = s.size();
        int idx = 0;
        for (idx = 0; idx < length; idx++)
        {
            if (s[idx] != '0')
                break;
        }
        s = s.substr(idx);
        length = s.size();
        if (length==0)
            return 0;
        
        int n = (length+1)/2; // 2*char number
        sum = 1;
        for (int i = 1; i <= n; i++)
        {
            int count = 0;
            cur_s = "";
            backtrack(s,0,i, count);
            sum += count;
        }
        return sum;
    }

    bool backtrack(string &s, int start, int num, int &count){

        if (num<=0)
        {
            count=1;
            cout << cur_s << endl;
            return true;
        }
        int cur = 0;
        for (int i = start; i < s.size()-1; i++)
        {
            cur_s = cur_s + s[i];
            if (twoCharNum(s[i],s[i+1]))
            {
                cur_s = cur_s + "+" + s.substr(i,2);
                if (backtrack(s, start+2,num-1, cur))
                {
                    count += cur;
                }
                cur_s = cur_s.substr(0, cur_s.size()-3);
            }
            cur_s = cur_s.substr(0, cur_s.size()-1);
        }
        return (count>0);
    }
    bool twoCharNum(char &a ,char &b){
        if (a=='1')
            return true;
        if (a=='2')
        {
            if ((b>='0') && (b <= '6'))
                return true;
        }
        return false;
    }
};