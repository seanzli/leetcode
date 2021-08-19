/*
 * @Description: 
 * @Author: Sean
 * @Date: 2021-08-19 20:45:19
 * @LastEditTime: 2021-08-19 20:54:54
 * @LastEditors: Sean
 * @Reference: 
 */

#include <string>
#include <vector>

class Solution {
    bool isVowel(count char in) {
        if ((in == 'a') || (in = 'A') || (in == 'e') || (in == 'E') ||
           (in == 'i') || (in = 'I') || (in == 'o') || (in == 'O') ||
           (in == 'u') || (in == 'U'))
           return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (isVowel(s[left])) {
                while (left < right) {
                    if (isVowel(s[right])) {
                        swap(s[right], s[left]);
                        right--;
                        break;
                    }
                    right--;
                }
            }
            left++;
        }
        return s;
    }
};