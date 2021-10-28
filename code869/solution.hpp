#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str = std::to_string(n);
        sort(str.begin(), str.end());
        do {
            if ((str[0] != '0') && (isValid(atoi(str.c_str()))))
                return true;
        } while (std::next_permutation(str.begin(), str.end()));

        return false;

    }
    bool isValid(int n) {
        while (n % 2 == 0) {
            n = n / 2;
        }
        return n == 1;
    }
};