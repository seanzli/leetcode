#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        double out = 0.0;
        bool flag = (x>=0);
        
        if ((x>INT_MAX) || (x<=INT_MIN))
            return 0;


        if (!flag)
            x = (-1)*x;

        int cur = 0;
        while (x>0){
            cur = x%10;
            out = out*10.0 + cur;
            x = x/10;
        }
        if (!flag)
        {
            out = (-1)*out;
        }
        if ((out > (INT_MAX)) || (out < INT_MIN))
        {
            out = 0.0;
        }
        return (int)(out);
    }
};