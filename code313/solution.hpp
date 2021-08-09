/*
 * @Description: 
 * @Author: Sean
 * @Date: 2021-08-09 20:00:10
 * @LastEditTime: 2021-08-09 20:35:23
 * @LastEditors: Sean
 * @Reference: 
 */

#include <vector>
#include <limits>
#include <limits.h>

using namespace std;

class Solution {
public:
    /* n指针动态规划，每次遍历k个值两次求最小值并维护指针，循环n次 */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> plist(k, 0);//指针列表
        vector<int> nums(1,1);//初始化为1个1
        for(int i = 1; i < n; i++){
            int m = INT_MAX;
            for(int i = 0; i < k; i++){//找到最小的数，并插入
                m = min(m, primes[i] * nums[plist[i]]);
            }
            nums.push_back(m);
            for(int i = 0; i < k; i++){//所有可以得到这个指的指针移动一位，这里防止了相同数字的产生
                if(primes[i] * nums[plist[i]] == m){
                    plist[i]++;
                }
            }
        }
        return nums[n-1];
    }
};