#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numWays(string s) {
        // calc number of '1'
        int sum = 0;
        for (char cur : s) {
            if (cur == '1')
                sum++;
        }
        // can not split return 0
        if (sum / 3 * 3 != sum)
            return 0;
        sum /= 3;
        
        // all zero 
        if (sum == 0)
            return (s.size() - 1) * (s.size() - 2) / 2;
        
        // split
        int left = 0, mid_left, mid_right, right;
        int count = 0;
        for (left = 0; left < s.size(); left++) {
            if (s[left] == '1') {
                count++;
                if (count == sum)
                    break;
            }
        }
        count = 0;
        for (mid_left = left + 1; mid_left < s.size(); mid_left++) {
            if (s[mid_left] == '1') {
                count++;
                break;
            }
        }
        count = 0;
        for (mid_right = mid_left; mid_right < s.size(); mid_right++) {
            if (s[mid_right] == '1') {
                count++;
                if (count == sum)
                    break;
            }
        }
        count = 0;
        for (right = mid_right + 1; right < s.size(); right++) {
            if (s[right] == '1') {
                count++;
                break;
            }
        }
        return (mid_left - left) * (right - mid_right);
    }
};