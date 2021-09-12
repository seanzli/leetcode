#include <string>

using namespace std;

// class Solution {
// public:
//     bool checkValidString(string s) {
//         int cur = 0;
//         return dfs(s, 0, cur);
//     }
//     bool dfs(string& s, const int i, int cur) {
//         if (cur < 0)
//             return false;
//         if (i == s.size()) {
//             return cur == 0;
//         }
//         if (s[i] == '(') {
//             ++cur;
//             return dfs(s, i + 1, cur);
//         } else if (s[i] == ')') {
//             --cur;
//             if (cur < 0)
//                 return false;
//             return dfs(s, i + 1, cur);
//         } else { // *
//             if (dfs(s, i + 1, cur + 1)
//                 || dfs(s, i + 1, cur)
//                 || dfs(s, i + 1, cur - 1))
//                 return true;
//             else
//                 return false;
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool checkValidString(string s) {
        int left = 0, right = 0;
        for (char& c : s) {
            if (c == '(') {
                ++left;
                ++right;
            } else if (c == ')') {
                --left;
                --right;
            } else {
                --left;
                ++right;
            }
            left = std::max(left, 0);
            if (left > right)
                return false;
        }
        return left == 0;
    }
};