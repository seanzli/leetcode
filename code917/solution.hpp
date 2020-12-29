#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        char *out = (char*)S.c_str();
        char temp = '0';

        for (int idx1 = 0, idx2=S.size()-1;idx1<idx2;)
        {
            if (temp=='0')
            {   if(((out[idx1]>='a') &&(out[idx1]<='z')) 
                        || ((out[idx1]>='A') &&(out[idx1]<='Z')))
                {
                    temp = out[idx1];
                }
                else
                {
                    idx1++;
                    continue;
                }
            }
            

            if(((out[idx2]>='a') &&(out[idx2]<='z')) 
                || ((out[idx2]>='A') &&(out[idx2]<='Z')))
            {
                out[idx1] = out[idx2];
                out[idx2] = temp;
                temp = '0';
                idx1++;
                idx2--;
                continue;
            }
            else
            {
                idx2--;
                continue;
            } 
        }
        return S;
    }
};