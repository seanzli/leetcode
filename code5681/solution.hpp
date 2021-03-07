#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/* class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> vec;
        vec.push_back(1);
        int max_idx = 0;
        while (vec.back() < n) {
            vec.push_back(vec.back() * 3);
            max_idx++;
        }
        
        int left = 0;
        for (left = 0; left < max_idx; left++) {
            int right = max_idx;
            int mid = left + 1;
            while (mid < right) {
                int sum = vec[left] + vec[mid] + vec[right];
                if (sum == n)
                    return true;
                else if (sum > n)
                    right--;
                else
                    mid++;
            }
        }
        return false;
    }
}; */

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int start = 1;
        while(n >= start){ // 注意n就是一个3的幂
            start *= 3;
        }
        if(start > 1) start /= 3; // 注意边界问题
        while(n > 0 && start > 0){
            if(n >= start) n -= start;
            start /= 3;
        }
        return n == 0;
    }
};