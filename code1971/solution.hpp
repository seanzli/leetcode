#include <iostream>

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    unordered_map<int, unordered_set<int>> hash;
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n, 0); // 0 : not visited, 1 : checking, 2 : checked;

        for (const auto& itr : edges) {
            hash[itr[0]].insert(itr[1]);
            hash[itr[1]].insert(itr[0]);
        }

        return dfs(source, destination, visited);
    }

    bool dfs(int source, int destination, vector<int>& visited) {
        if (source == destination)
            return true;
        if (visited[source] == 2)
            return false;
        if (visited[source] == 1)
            return false;
        visited[source] = 1;
        for (const auto& itr : hash[source]) {
            if (dfs(itr, destination, visited))
                return true;
        }
        visited[source] = 2;
        return false;
    }
};