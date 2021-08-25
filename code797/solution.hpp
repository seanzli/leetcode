/*
 * @Description: 
 * @Author: Sean
 * @Date: 2021-08-25 20:37:04
 * @LastEditTime: 2021-08-25 20:54:51
 * @LastEditors: Sean
 * @Reference: 
 */

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        queue<pair<int, vector<int>>> que; // node -> path
        que.push({0, vector<int>{}});
        while (que.size()) {
            int n = que.size();
            for (int i = 0; i < n; ++i) {
                int cur = que.front().first; 
                vector<int> cur_path = que.front().second;
                que.pop();

                cur_path.push_back(cur);
                if (cur == graph.size() - 1) {
                    res.push_back(cur_path);
                } else {
                    for (int j = 0; j < graph[cur].size(); ++j) {
                        que.push({graph[cur][j], cur_path});
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> cur;
        cur.push_back(0);
        dfs(0, graph , cur);
        return res;
    }
    void dfs(const int node, vector<vector<int>>& graph, vector<int>& vec) {
        if (node == graph.size() - 1) {
            res.push_back(vec);
            return;
        }

        for (int i = 0; i < graph[node].size(); ++i) {
            vec.push_back(graph[node][i]);
            dfs(graph[node][i], graph, vec);
            vec.pop_back();
        }
        return;
    }
};