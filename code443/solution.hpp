#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int compress(vector<char>& chars) {
//         char cur = chars[0];
//         int size = 0;
//         int count = 1;
//         for (int i = 1; i < chars.size(); i++) {
//             if (chars[i] == cur)
//                 count++;
//             else {
//                 chars[size++] = cur;
//                 if (count > 1) {
//                     string str = to_string(count);
//                     for (int j = 0; j < str.size(); j++) {
//                         chars[size++] = str[j];
//                     }
//                 }
//                 cur = chars[i];
//                 count = 1;
//             }
//         }
//         chars[size++] = cur;
//         if (count > 1) {
//             string str = to_string(count);
//             for (int j = 0; j < str.size(); j++) {
//                 chars[size++] = str[j];
//             }
//         }
//         return size;
//     }
// };

class Solution {
public:
    int compress(vector<char>& chars) {
        string res;
        int count = 1;
        char cur = chars[0];
        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] == cur) {
                count++;
            } else {
                res += cur;
                if (count > 1)
                    res += to_string(count);
                cur = chars[i];
                count = 1;
            }
        }
        res += cur;
        if (count > 1)
            res += to_string(count);
        chars = vector<char>(res.begin(), res.end());
        return res.size();
    }
};