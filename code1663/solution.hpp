#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        int bound = (k - n) / 25; // 需要置为 ‘z’的数量
        int r = (k - n) % 25; // 第一个 z 前面那位
        if (n - bound - 1 < 0) {
            return string(bound, 'z');
        } 
        return string (n - bound - 1, 'a') + string(1, 'a' + r) + string(bound, 'z');
    }
};