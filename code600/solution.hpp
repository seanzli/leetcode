#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static const int N = 35;
    int f[N][2];
public:
    int findIntegers(int num) {
        // 数位DP
        // 预处理不包含连续1的个数 f[i][j]表示长度为i， 最高位为j的不含连续1的种类数
        f[0][0] = 1;
        for(int i = 1; i < N; i++)
        {
            f[i][0] = f[i - 1][0] + f[i - 1][1];
            f[i][1] = f[i - 1][0];
        }
        vector<int> nums;
        while(num)
        {
            nums.push_back(num % 2);
            num /= 2;
        }
        // res 记录最终答案， last记录上一位的状态
        int res = 0;
        int last = 0;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            int x = nums[i];
            if(x)
            {
                res += f[i + 1][0];
                // 连续两个1 直接break
                if(x && last) break;
            }
            last = x;
            // 走到最后仍然没有跳出， 证明num合法
            if(!i) res++;
        }
        return res;
    }
};