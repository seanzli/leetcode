#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    int reverseBits(int num) {
        bitset<32> curset(num);
        string str = curset.to_string();
        int left = 0, right = 0;
        int max_length = 0;
        int count = 0;
        while (right < str.size()) {
            if (str[right] == '0') {
                count++;
                while (count > 1) {
                    if (str[left++] == '0')
                        count--;
                }
            }
            max_length = max(max_length, right - left + 1);
            right++;
        }
        return max_length;
    }
};