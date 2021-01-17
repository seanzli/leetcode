#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        int orj = x;
        double out = 0.0;
        while (x>0){
            out = out*10+x%10;
            x=x/10;
        }
        if ((out>INT_MAX) || (out<INT_MIN))
            return false;
        
        if ((int)(out) == orj)
            return true;
        return false;
    }
};