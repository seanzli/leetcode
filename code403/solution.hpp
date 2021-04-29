#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <functional>

using namespace std;

class Solution {
    unordered_map<int, int> unvisited;
public:
    bool canCross(vector<int>& stones) {
        for (int i = 0; i < stones.size(); i++)
            unvisited[stones[i]] = i;        
        dfs(stones, 0, 1);
        return unvisited[stones.back()] == -1;
    }

    void dfs(vector<int>& stones, int idx, int k) {
        if (unvisited[stones.back()] == -1 || unvisited[stones[idx]] == -1)
            return;
        if (unvisited.find(stones[idx] + k - 1) != unvisited.end() &&
            unvisited[stones[idx] + k - 1] >= 0)
            dfs(stones, unvisited[stones[idx] + k - 1], k - 1);
        if (unvisited.find(stones[idx] + k) != unvisited.end() && 
            unvisited[stones[idx] + k] >= 0)
            dfs(stones, unvisited[stones[idx] + k], k);
        if (unvisited.find(stones[idx] + k + 1) != unvisited.end() &&
            unvisited[stones[idx] + k + 1] >= 0)
            dfs(stones, unvisited[stones[idx] + k + 1], k + 1);
        unvisited[stones[idx]] = -1;
        return;
    }
};

/* class Solution {
public:
    vector<int> idx_diff = {-1, 0, 1};
    bool BackTracking(vector<int>& stones, int idx, int k) {
        if (idx == stones.size() - 1) 
            return true;
        for (int next = idx + 1; next < stones.size() && stones[idx] + k + 1 >= stones[next]; ++next) {  // stones[idx] + k + 1 >= stones[next] 提前剪枝
            for (auto &diff : idx_diff) {
                if (stones[idx] + k + diff == stones[next]) {
                    if (BackTracking(stones, next, k + diff)) 
                        return true;
                }
            }
        }
        return false;
    }

    bool canCross(vector<int>& stones) {
        return BackTracking(stones, 0, 0);
    }
}; */
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1) return false;
        map<int,int> mp;
        map<int,bool> f; //记忆化cache
        for(int i = 0; i < n; i++) mp[stones[i]] = i;

        std::function<bool(int,int)> dfs = [&](int idx,int k){
            auto key = idx * 10000 + k; //key值可以这样映射
            if(f.count(key)) return f[key];
            if(idx == n - 1) return true;
            for(int i = -1; i <= 1; i++){
                if(k + i == 0) continue;
                int next = stones[idx] + k + i;
                if(mp.count(next)){
                    bool cur = dfs(mp[next],k + i);
                    f[key] = cur; 
                    if(cur) return true;
                }
            }
            f[key] = false;
            return false;
        };
        
        return dfs(1,1);
    }
};
