#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if(n==0)
            return res;
        for(int i=0;i<n;i++)
        {
            for(int j=res.size()-1;j>=0;j--)
            {
                res.push_back((res[j]<<1)+1);
            }
            for(int j=0;j<res.size()/2;j++)
            {
                res[j]=res[j]<<1;
            }
        }
        return res;
    }
/*     vector<int> grayCode(int n) {
        vector<int> vAns(1<<n, 0);
        vAns[1] = 1;
        for(int i = 1; i < n; ++i) 
        {
            for(int j = 0; j < (1<<i); ++j) 
                vAns[(1<<(i+1))-j-1] = vAns[j] | (1<<i);
        }
        return vAns;
    } */
    
    string dec2bin(int decVal){
        string value = "";
        bool isMinus = false;
        if (decVal < 0)
        {
            isMinus = true;
        }
            
        while (decVal > 0)
        {
            if (decVal % 2)
                value = '1' + value;
            else
                value = '0' + value;
            decVal = decVal / 2;
        }
        if (isMinus)
            value = '-' + value;
        return value;
    }
};