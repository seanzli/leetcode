#include <cstdio>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        long max_idx, min_idx;
        getMax(buildings, min_idx, max_idx);
        vector<int> sky(max_idx+1,0);
        int idx = 0; // 
        for (int i = min_idx; i <= max_idx; i++)
            sky[i] = getHeightest(buildings, i, idx);
        
        vector<vector<int>> out;
        vector<int> cur={min_idx, sky[min_idx]};
        out.push_back(cur);
        for (int i = min_idx+1; i <= max_idx; i++)
        {
            if (sky[i] != cur[1]){
                cur = {i, sky[i]};
                out.push_back(cur);
            }
        }
        return out;
    }

    void getMax(vector<vector<int>>& buildings, long &min_idx, long &max_idx){
        min_idx = buildings[0][0];
        max_idx = INT_MIN;
        for (vector<int> i : buildings)
        {
            max_idx = max(max_idx, i[1]);
        }
        return ;
    }

    int getHeightest(vector<vector<int>>&buildings, int cur ,int &idx){
        
        int height = 0;

        for (int i = idx; i < buildings.size(); i++)
        {
            if (buildings[i][1] < cur)
                idx++;
            else if ((buildings[i][0] <= cur) && (buildings[i][1] > cur))
                height = max(height, buildings[i][2]);
            else if (buildings[i][0] > cur)
                return height;
        }
        return height;
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> all;
        vector<vector<int>> res;
        
        for (auto& e : buildings) {
            all.insert(make_pair(e[0], -e[2])); // critical point, left corner
            all.insert(make_pair(e[1], e[2])); // critical point, right corner
        }
        
        multiset<int> heights({0}); // 保存当前位置所有高度。
        vector<int> last = {0, 0}; // 保存上一个位置的横坐标以及高度
        for (auto& p : all) {
            if (p.second < 0) heights.insert(-p.second); // 左端点，高度入堆
            else heights.erase(heights.find(p.second)); // 右端点，移除高度
            
            // 当前关键点，最大高度
            auto maxHeight = *heights.rbegin();
            
            // 当前最大高度如果不同于上一个高度，说明这是一个转折点
            if (last[1] != maxHeight) {
                // 更新 last，并加入结果集
                last[0] = p.first;
                last[1] = maxHeight;
                res.push_back(last);
            }
        }
        
        return res;
    }
};