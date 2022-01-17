#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

//class Solution {
//    unordered_map<int,unordered_set<int>> hash; // course -> base
//public:
//    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//        vector<int> res;
//        for (int i = 0; i < numCourses; ++i) {
//            hash[i];
//        }
//        for (const auto& itr : prerequisites) {
//            hash[itr[0]].insert(itr[1]);
//            hash[itr[1]];
//        }
//        while (!hash.empty()) {
//            int cur = zeroInDegree();
//            if (cur == -1)
//                return {};
//            deleteBase(cur);
//            res.push_back(cur);
//            hash.erase(cur);
//        }
//        return res;
//    }
//    int zeroInDegree() {
//        for (const auto& itr : hash) {
//            if (itr.second.empty())
//                return itr.first;
//        }
//        return -1;
//    }
//
//    void deleteBase(int cur) {
//        for (auto& itr : hash) {
//            if (itr.second.count(cur))
//                itr.second.erase(cur);
//        }
//    }
//};

class Solution {
private:
    vector<int> result;
    vector<vector<int>> edge;
    vector<int> visite;
    bool valid = true;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if (n==0){
            for (int i = 0; i < numCourses; i++)
                result.push_back(i);
            return result;
        }

        visite.resize(numCourses);
        edge.resize(numCourses);
        for (auto i : prerequisites)
            edge[i[1]].push_back(i[0]);

        for (int i = 0; i < numCourses && valid; i++)
        {
            if (!visite[i])
                dfs(i);
        }
        if (!valid)
            return {};
        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(int i){
        visite[i] = 1;
        for (int v : edge[i]){
            if (visite[v]==0){
                dfs(v);
                if (!valid)
                    return;
            }
            else if (visite[v]==1){
                valid = false;
                return;
            }
        }
        visite[i] = 2;
        result.push_back(i);
    }
};