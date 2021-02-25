#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int row = wall.size();
        unordered_map<int, int> hash;
        int cur_sum = 0;
        for (vector<int> cur : wall) {
            cur_sum = 0;
            for (int i : cur) {
                cur_sum += i;
                hash[cur_sum]++;
            }
        }
        hash.erase(cur_sum);

        int min_row = row;
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
            min_row = min(min_row, row - itr->second);
        }
        return min_row;
    }
};