#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findString(vector<string>& words, string s) {
        int n = words.size();
        int left = 0, right = n - 1;
        for ( ; left < n; left++) {
            if (words[left].size() > 0)
                break;
        }
        for ( ; right >=0 ;right--) {
            if (words[right].size() > 0)
                break;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            while (words[mid].size() == 0)
                mid++;
            if (words[mid] == s) {
                return mid;
            }
            else if (words[mid] > s) {
                right = mid - 1;
                while (words[right].size() == 0)
                    right--;
            } else {
                left = mid + 1;
                while (words[left].size() == 0)
                    left++;
            }

        }
        return -1;
    }
};