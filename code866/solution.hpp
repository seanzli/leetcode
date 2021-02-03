#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

class Solution {
public:
    int primePalindrome(int N) {
        if (N==1)    return 2;
        while (1){
            generatePalindrome(N);
            if (isPrime(N))
                return N;
            N = N+1;
        }
    }

    void generatePalindrome(int &n){
        string s = to_string(n);
        int mid = s.size()/2;
        while (1) {
            // 制造回文数：把前半段翻转一下复制到后半段
            for (int i = 0; i < mid; i++) {
                s[s.size() -1 - i] = s[i];
            }
            // 判断制造出来的数是否>=n
            int tmp = atoi(s.c_str());
            if (tmp >= n){
                n = tmp; // 如果>=n，返回这个造出来的数
                return;
            } 
            // 如果比n小，那前半段+1
            else {
                int j = s.size() % 2 == 1? mid: mid-1; // 如果是奇数长度，最靠近中轴的是s[mid]；如果是偶数长度，最靠近中轴的是s[mid-1]
                // 有9要进位（不用考虑999xxx这样首位要进位的，因为999999这个回文数肯定>=所有999xxx形式的n）
                while (s[j] == '9'){
                    s[j--] = '0';
                }
                s[j]++;
            }
        }
        n = atoi(s.c_str());
    }
    bool isPrime(int n){
        int cur = sqrt(n)+1;
        for (int i = 2; i<= cur; i++){
            if (n%i==0)
                return false;
        }
        return true;
    }
};