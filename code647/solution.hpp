#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

/* class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        int left = 0, right = 0;
        while(left < n && right < n) {
            int cur_left = left;
            int cur_right = right;
            while (cur_left >=0 && cur_right < n && s[cur_right] == s[cur_left]) {
                cur_left--;
                cur_right++;
                count++;
            }
            if (right > left)
                left++;
            else
                right++;
        }
        return count;
    }
}; */

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();

        auto isPalindromicStr = [&](int a, int b){
            while (a >= 0 && b < n && s[a--] == s[b++]) {
                count++;
            }
            return;
        };

        int left = 0, right = 0;
        while(left < n && right < n) {
            isPalindromicStr(left, right);
            if (right > left)
                left++;
            else
                right++;
        }
        return count;
    }
};