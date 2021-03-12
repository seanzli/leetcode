#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    vector<pair<int, int>> res;
    int max_length = 1;
public:
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        vector<pair<int, int>> vec;
        for (int i = 0; i < height.size(); i++) {
            vec.push_back(make_pair(height[i], weight[i]));
        }

        sort(vec.begin(), vec.end());
        for (int i = 0; i < vec.size() - max_length; i++) {
            res.push_back(vec[i]);
            dfs(vec, i + 1);
            res.pop_back();
        }
        return max_length;
    }

    void dfs(vector<pair<int, int>> & vec, int idx) {
        if (idx == vec.size()) {
            return;
        }

        auto cur = res.back();
        for (int i = idx; i < vec.size() + res.size() - max_length; i++) {
            if (cur.first < vec[i].first && cur.second < vec[i].second) {
                res.push_back(vec[i]);
                max_length = max(max_length, (int)(res.size()));
                dfs(vec, i + 1);
                res.pop_back();
            }
        }
    }
};