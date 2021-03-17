#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    const int INF = 1e8;
    bool dfs(vector<int>& nums, int i, int N, int dir) {
        // 遇到不符合条件的点，返回false
        if (nums[i] == 0) return false;
        // 遇到在考察中的点，说明形成了闭环，返回true
        if (nums[i] == INF) return true;
        int ndir = nums[i] > 0 ? 1 : -1;
        if (ndir == dir) {
            int j = (N + (nums[i] + i) % N) % N;
            // 将i处的值设为INF，标志i点在考察中
            nums[i] = INF;
            if (j != i && dfs(nums, j, N, dir)) {
                return true;
            } else {
                // i点不符合条件，赋值为0
                nums[i] = 0;
                return false;
            }
        }
        return false;
    }

    bool circularArrayLoop(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            if (nums[i] == 0) continue;
            int dir = nums[i] > 0 ? 1 : -1;
            if (dfs(nums, i, N, dir)) {
                return true;
            }
        }
        return false;
    }
};