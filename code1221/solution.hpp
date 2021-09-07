#include <iostream>
#include <vector>
#include <string>

using namespace std;

// class Solution {
// public:
//     int balancedStringSplit(string s) {
//         int res = 0;
//         int r = 0, l = 0;
//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] == 'R')
//                 r++;
//             else
//                 l++;
//             if (r == l)
//                 res++;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int b = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'R')
                ++b;
            else
                --b;
            if (b == 0)
                res++;
        }
        return res;
    }
};