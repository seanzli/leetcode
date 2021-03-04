#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<unordered_set<int>> graph(n + 1);
        for (const auto& e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        vector<double> p(n + 1);
        if (t < 0) {
            return 0.0;
        }
        p[1] = 1.0;
        dfs(graph, 1, t, target, p);

        return p[target];
    }

private:
    void dfs(vector<unordered_set<int>>& graph, int src, int t, int target, vector<double>& p) {
        if (src == target) {
           if (t == 0 || (t > 0 && graph[src].empty())) {
               return;
           } else if (!graph[src].empty() && t > 0) {
               p[target] = 0.0; // cannot stop on branches
           }
        }
        if (t <= 0) {
            return; 
        }
        for (const auto& neighbor : graph[src]) {
            graph[neighbor].erase(src);
            p[neighbor] = p[src] / (graph[src].size());
            dfs(graph, neighbor, t - 1, target, p);
        }
    }
};