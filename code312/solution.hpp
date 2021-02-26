#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        queue<pair<vector<int>, int>> que; // cur num -> sum
        que.push(make_pair(nums, 0));
        while (1) {
            int n = que.size();
            vector<int> cur_vec;
            for (int i = 0; i < n; i++) {
                auto cur = que.front(); que.pop();
                for (int i = 0; i < cur.first.size(); i++) {
                    cur_vec = cur.first;
                    cur_vec.erase(cur_vec.begin() + i);
                    int value = cur.first[i] * 
                                (i > 0 ? cur.first[i - 1] : 1) * 
                                (i < cur.first.size() - 1 ? cur.first[i + 1] : 1);
                    que.push(make_pair(cur_vec, cur.second + value));
                }
            }
            if (cur_vec.size() == 0)
                break;
        }
        int max_value = 0;
        while (que.size()) {
            max_value = max(que.front().second, max_value);
            que.pop();
        }
        return max_value;
    }
};

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> rec(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j <= n + 1; j++) {
                for (int k = i + 1; k < j; k++) {
                    int sum = val[i] * val[k] * val[j];
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = max(rec[i][j], sum);
                }
            }
        }
        return rec[0][n + 1];
    }
};