#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> g(n);
        for (auto itr : graph) {
            g[itr[0]].push_back(itr[1]);
        }

        vector<bool> visited(n, false);
        queue<int> que;
        for (auto itr : g[start])
            que.push(itr);
        
        visited[start] = true;
        while (que.size()) {
            int n = que.size();
            for (int i = 0; i < n; i++) {
                int cur = que.front();
                que.pop();
                if (visited[cur])
                    continue;
                if (cur == target)
                    return true;
                visited[cur] = true;
                for (auto itr : g[cur])
                    que.push(itr);
            }
        }
        return false;
    }
};