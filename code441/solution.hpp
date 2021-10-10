#include <iostream>

class Solution {
public:
    int arrangeCoins(int n) {
        int cur = 1;
        int res = 0;
        while (n >= cur) {
            n = n - cur;
            ++cur;
            ++res;
        }
        return res;
    }
};