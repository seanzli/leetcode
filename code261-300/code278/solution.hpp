#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0, end = n, mid=0;
        while(start <= end){
            mid = (end - start)/2 + start;
            if (isBadVersion(mid))
                end = mid;
            else
                start = mid + 1;
        }
        return start;
    }
};