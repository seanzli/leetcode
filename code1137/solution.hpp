/*
 * @Description: 
 * @Author: Sean
 * @Date: 2021-08-08 09:48:00
 * @LastEditTime: 2021-08-08 09:50:10
 * @LastEditors: Sean
 * @Reference: 
 */

class Solution {
public:
    int tribonacci(int n) {
        int t0 = 0, t1 = 1, t2 = 1, t3;
        if (n == 0)
            return t0;
        else if (n == 1)
            return t1;
        else if (n == 2)
            return t2;
        for (int i = 2; i < n; ++i) {
            t3 = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }
        return t2;
    }
};