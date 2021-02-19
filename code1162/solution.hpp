#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int, int>> ground, see;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0)
                    see.push_back(make_pair(i, j));
                else
                    ground.push_back(make_pair(i, j));
            }
        }
        if (ground.size() == 0 || see.size() == 0)
            return -1;
        
        int max_dis = 0, cur_dis = 0;
        for (auto itr_see : see) {
            int min_dis = INT8_MAX;
            for (auto itr_ground : ground) {
                cur_dis = abs(itr_see.first - itr_ground.first) + abs(itr_see.second - itr_ground.second);
                min_dis = min(min_dis, cur_dis);
            }
            max_dis = max(max_dis, min_dis);
        }
        return max_dis;
    }
};