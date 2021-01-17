#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cur = 0;
        int i= digits.size()-1;
        digits[i]++;
        while (digits[i]>9)
        {
            digits[i] = digits[i] - 10;
            i--;
            if (i>=0)
            {
                digits[i]++;
            }
            else
            {
                vector<int> out = {1};
                out.insert(out.end(), digits.begin(), digits.end());
                return out;
            }
        }
        return digits;
    }
};