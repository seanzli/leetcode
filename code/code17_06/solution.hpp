#include <cstdio>
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOf2sInRange(int n) {
        long base = 1, total = 0;
        int pre = n/(10);
        int exatnum = n%10;
        int post = 0;

        while(n != post){
            if(exatnum>2){
                total += (pre+1)*base;
            } else if(exatnum==2){
                total += pre*base + post+1;
            } else {
                total += pre*base;
            }

            post += exatnum*base;
            exatnum = pre%10;
            pre /= 10;

            base *= 10;
        }
        return total;
    }
};