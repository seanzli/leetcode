#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int i = 1;
        int j = n;
        while (i <= j) {
            if (k > 1) {
                // 按照交替i,j一小一大的方法生成前K-1个数
                if (k % 2 != 0) {
                    res.push_back(i);
                    i++;
                } else {
                    res.push_back(j);
                    j--;
                }
                k--;
            } else {
                // 按照生序的方法生成剩余排列
                res.push_back(i);
                i++;
            }
        }

        return res;
    }
};