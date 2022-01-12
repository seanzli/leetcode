#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include <stack>

using namespace std;


//class Solution {
//private:
//    vector<vector<int>> edges;
//    vector<int> visited;
//    bool valid = true;
//
//public:
//    void dfs(int u) {
//        visited[u] = 1;
//        for (int v: edges[u]) {
//            if (visited[v] == 0) {
//                dfs(v);
//                if (!valid) {
//                    return;
//                }
//            }
//            else if (visited[v] == 1) {
//                valid = false;
//                return;
//            }
//        }
//        visited[u] = 2;
//    }
//
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        edges.resize(numCourses);
//        visited.resize(numCourses);
//        for (const auto& info: prerequisites) {
//            edges[info[1]].push_back(info[0]);
//        }
//        for (int i = 0; i < numCourses && valid; ++i) {
//            if (!visited[i]) {
//                dfs(i);
//            }
//        }
//        return valid;
//    }
//};

//class Solution {
//public:
//    unordered_map<int, vector<int>> hash; // course -> base course;
//    unordered_set<int> visited;
//    unordered_set<int> node;
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        for (const auto& itr : prerequisites) {
//            hash[itr[1]].emplace_back(itr[0]);
//            node.insert(itr[0]);
//            node.insert(itr[1]);
//        }
//        stack<int> stack_;
//        for (const auto& itr : node) {
//            if (!visited.count(itr))
//                topologicalSort(itr, stack_);
//        }
//
//        return stack_.size() == numCourses;
//    }
//
//private:
//    void topologicalSort(int course, stack<int>& s) {
//        visited.insert(course);
//        for (const auto& itr : hash[course]) {
//            if (!visited.count(itr)) {
//                topologicalSort(itr, s);
//            }
//        }
//        s.push(course);
//    }
//};

//class Solution {
//    unordered_map<int, unordered_set<int>> hash; // course -> base;
//public:
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        for (const auto& itr : prerequisites) {
//            hash[itr[1]].insert(itr[0]);
//            hash[itr[0]];
//        }
//
//        while (!hash.empty()) {
//            int root = getRoot();
//            if (root == -1)
//                return false;
//            hash.erase(root);
//            deleteRoot(root);
//        }
//        return true;
//    }
//
//private:
//    int getRoot() {
//        for (auto& itr : hash) {
//            if (itr.second.empty())
//                return itr.first;
//        }
//        return -1;
//    }
//
//    void deleteRoot(int root) {
//        for (auto& itr : hash) {
//            if (itr.second.count(root))
//                itr.second.erase(root);
//        }
//    }
//};

class Solution {
    unordered_map<int, vector<int>> hash; // course -> first course vec
    bool valid = true;
    unordered_set<int> safe;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (const auto& itr : prerequisites) {
            hash[itr[0]].emplace_back(itr[1]);
        }
        if (hash.empty())
            return true;
        unordered_set<int> visited;
        for (const auto& itr : hash) {
            if (safe.count(itr.first))
                continue;
            dfs(itr.first, visited);
            if (valid)
                safe.insert(itr.first);

        }
        return valid;
    }

private:
    void dfs(const int course, unordered_set<int>& visited) {
        if (!valid)
            return;
        if (visited.count(course)) {
            valid = false;
            return;
        }

        visited.insert(course);
        for (size_t i = 0; i < hash[course].size() && valid; ++i) {
            if (safe.count(hash[course][i]))
                continue;
            dfs(hash[course][i], visited);
            if (valid)
                safe.insert(hash[course][i]);
        }
        visited.erase(course);
    }
};