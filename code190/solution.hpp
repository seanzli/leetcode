#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t out = 0;
        for (int i = 0; i < 32; i++)
        {
            out = (out << 1) | (n & 0x1);
            n >>= 1;
        }
        return out;
    }
};