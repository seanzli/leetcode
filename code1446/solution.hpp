#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// class Solution {
// public:
//     int maxPower(string s) {
//         int left = 0, right = 0;
//         int max_length = 0;
//         for ( ;right<s.size(); right++){
//             while(left<=right && s[left]!=s[right])
//                 left++;
//             max_length = max(max_length, right-left+1);
//         }
//         return max_length;
//     }
// };

class Solution {
public:
    int maxPower(string s) {
        int res = 1;
        int cur = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++cur;
            } else {
                res = max(res, cur);
                cur = 1;
            }
        }
        return max(res, cur);
    }
};