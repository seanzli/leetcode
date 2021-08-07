#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

// class Solution {
// public:
//     const int INF = 1e8;
//     bool dfs(vector<int>& nums, int i, int N, int dir) {
//         // 遇到不符合条件的点，返回false
//         if (nums[i] == 0) return false;
//         // 遇到在考察中的点，说明形成了闭环，返回true
//         if (nums[i] == INF) return true;
//         int ndir = nums[i] > 0 ? 1 : -1;
//         if (ndir == dir) {
//             int j = (N + (nums[i] + i) % N) % N;
//             // 将i处的值设为INF，标志i点在考察中
//             nums[i] = INF;
//             if (j != i && dfs(nums, j, N, dir)) {
//                 return true;
//             } else {
//                 // i点不符合条件，赋值为0
//                 nums[i] = 0;
//                 return false;
//             }
//         }
//         return false;
//     }

//     bool circularArrayLoop(vector<int>& nums) {
//         int N = nums.size();
//         for (int i = 0; i < N; ++i) {
//             if (nums[i] == 0) continue;
//             int dir = nums[i] > 0 ? 1 : -1;
//             if (dfs(nums, i, N, dir)) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0)
                return false;
            unordered_set<int> visited;
            if (dfs(nums, visited, i, n, nums[i] > 0))
                return true;
        }
        return false;
    }
    
    bool dfs(vector<int>& nums, unordered_set<int>& visited, const int i, const int n, const bool b_positive) {
        if (nums[i] == 0)
            return false;
        if (visited.count(i) == 1)
            return true;
        visited.insert(i);
        int idx = (n + (nums[i] + i) % n) % n;
        if (nums[idx] == 0)
            return false;
        if (b_positive ^ (nums[idx] > 0)) // b_positive and nums[idx] have the same sign
            return dfs(nums, visited, idx, n, b_positive);
        return false;
    }
};