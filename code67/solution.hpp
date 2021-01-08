#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.size(), b.size());
        for (int i = a.size(); i < n; i++)
            a = "0"+a;
        for (int i = b.size(); i < n; i++)
            b = "0"+b;
        int cur = 0, flag=0;
        for (int i = n-1; i>=0; i--)
        {
            cur = binary2int(a[i])+binary2int(b[i])+flag;
            if (cur > 1)
            {
                flag=1;
                a[i] = cur-2+'0';
            }
            else
            {
                flag=0;
                a[i] = cur + '0';
            }
        }
        if (flag)
            return ("1"+a);
        return a;
    }
    int binary2int(char i){return i=='0'?0:1;}
};