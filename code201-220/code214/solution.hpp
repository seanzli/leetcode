#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n<2)
            return s;
        int i = n;
        for (; i >=0 ; i--)
        {
            if (isPalindrome(s.substr(0,i)))
                break;
        }
        string out = s.substr(i);
        reverse(out.begin(), out.end());
        return out + s;
    }

    bool isPalindrome(string s){
        if (s.size()<2)
            return true;
        int n = s.size();
        int start = 0, end = n-1;
        while (start < end){
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int base = 131, mod = 1000000007;
        int left = 0, right = 0, mul = 1;
        int best = -1;
        for (int i = 0; i < n; ++i) {
            left = ((long long)left * base + s[i]) % mod;
            right = (right + (long long)mul * s[i]) % mod;
            if (left == right) {
                best = i;
            }
            mul = (long long)mul * base % mod;
        }
        string add = (best == n - 1 ? "" : s.substr(best + 1, n));
        reverse(add.begin(), add.end());
        return add + s;
    }
};