#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int start = 0;
        int end = x/2;
        double mid;

        if (x<2)
            return x;

        while (end - start >1)
        {
            mid = ((double)(start+end))/2;
            if (mid*mid>x)
            {
                if (end != mid)
                    end = mid;
                else
                    end--;
            }
            else if (mid*mid<x)
            {
                if (start != mid)
                    start = mid;
                else
                    start++;
            }
            else
                return mid;
        }
        mid = end;
        if (mid*mid<=x)
            return end;
        return start;
    }
};