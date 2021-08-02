/*
 * @Description: 
 * @Author: Sean
 * @Date: 2021-08-02 21:35:23
 * @LastEditTime: 2021-08-02 22:41:03
 * @LastEditors: Sean
 * @Reference: 
 */

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> hash; // x -> (y, cost)
        for (const auto& itr : times) {
            hash[itr[0]].push_back(make_pair(itr[1], itr[2]));
        }

        unordered_map<int, int> cost_map; // y min_cost;
        cost_map[k] = 0;
        queue<pair<int, int>> que; // cur node, cost
        que.push(make_pair(k, 0));
        while (que.size()) { // bfs
            int cur = que.front().first; // cur node
            int cur_cost = que.front().second; // cur cost
            que.pop();
            for (const auto& itr : hash[cur]) {
                if (cost_map.find(itr.first) == cost_map.end()) { // not visited yet
                    cost_map[itr.first] = cur_cost + itr.second;
                    que.push(make_pair(itr.first, cost_map[itr.first]));
                }
                else if (cost_map[itr.first] <= cur_cost + itr.second) // cur node's cost dont need update
                    ;
                else {  // need to update the ons connect to this node
                    cost_map[itr.first] = cur_cost + itr.second;
                    que.push(make_pair(itr.first, cost_map[itr.first]));
                }
            }
        }

        if (cost_map.size() < n)
            return -1;
            
        int max_cost = 0;
        for (auto itr = cost_map.begin(); itr != cost_map.end(); itr++) {
            max_cost = max(max_cost, itr->second);
        }
        return max_cost;
    }

};