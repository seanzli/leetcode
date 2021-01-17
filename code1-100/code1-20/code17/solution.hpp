#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <list>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<string> int2string(char i)
    {
        vector<string> a;
        switch(i)
        {
            case '2': a = {"a","b","c"}; return a;
            case '3': a = {"d","e","f"}; return a;
            case '4': a = {"g","h","i"}; return a;
            case '5': a = {"j","k","l"}; return a;
            case '6': a = {"m","n","o"}; return a;
            case '7': a = {"p","q","r","s"}; return a;
            case '8': a = {"t","u","v"}; return a;
            case '9': a = {"w","x","y","z"}; return a;
            default: return a;
        }
        return a;
    }

    int sumInt(int *in, int num)
    {
        int sum = 0;
        for (int i = 0; i < num; i++)
            sum += in[i];
        return sum;
    }

    void idxSub(int *in,int *max, int num)
    {
        in[0]--;
        for (int i = 0; i < num-1; i++)
        {
            if (in[i]<0)
            {   
                in[i] = max[i]-1;
                in[i+1]--;
            }
            else
            {
                break;
            }
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> out;
        vector<vector<string>> base;
        char *p = (char*)digits.c_str();
        if (digits.size()<1)
            return out;
        string cur;
        int n = digits.size();
        int *max = new int[n]();
        int *idx = new int[n]();
        vector<string> temp;
        for (int i = 0; i < n; i++)
        {   
            temp = int2string(p[i]);
            base.push_back(temp);
            max[i] = temp.size();
            idx[i] = max[i]-1;
        }

        while (sumInt(idx,n)>0)
        {
            for (int i = 0; i < n; i++)
                cur += base[i][idx[i]];
            out.push_back(cur);
            idxSub(idx,max,n);
            cur="";
        }
        for (int i = 0; i < n; i++)
            cur += base[i][idx[i]];
        out.push_back(cur);
        return out;
    }
};