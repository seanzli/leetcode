/*
 * @Description: 
 * @Author: Sean
 * @Date: 2021-08-01 08:31:39
 * @LastEditTime: 2021-08-01 08:36:32
 * @LastEditors: Sean
 * @Reference: 
 */
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que; // num, idx
        for (int i = 0; i < mat.size(); ++i) {
            que.push(make_pair(accumulate(mat[i].begin(), mat[i].end(), 0), i));
        }
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(que.top().second);
            que.pop();
        }
        return res;
    }
};