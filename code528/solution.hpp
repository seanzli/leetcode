/*
 * @Description: 
 * @Author: Sean
 * @Date: 2021-08-30 20:52:52
 * @LastEditTime: 2021-08-30 20:59:21
 * @LastEditors: Sean
 * @Reference: 
 */

#include <vector>
#include <random>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    mt19937 gen;  // 伪随机数产生器， 用于产生高性能随机数
    uniform_int_distribution<int> dis; // 随机分布类，生成范围内的随机数
    vector<int> pre;

public:
    Solution(vector<int>& w)
    : gen(random_device{}())
    , dis(1, accumulate(w.begin(), w.end(), 0)) {
        partial_sum(w.begin(), w.end(), back_inserter(pre)); // partial_sum：求累加和，结果保存在迭代器中， back_inserter：末尾插入元素
    }

    int pickIndex() {
        int x = dis(gen);
        return lower_bound(pre.begin(), pre.end(), x) - pre.begin(); // 不大于num的第一个元素
    }
};