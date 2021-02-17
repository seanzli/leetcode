#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> value(n, INT_MAX);
        value[src] = 0;
        queue<int> indegree;
        indegree.push(src);
        int count = 0;
        while (indegree.size() && count <= K){
            int size = indegree.size();
            for (int i = 0; i < size; i++){
                int cur_src = indegree.front(); indegree.pop();
                for (auto cur = flights.begin(); cur != flights.end(); ){
                    if (cur_src == (*cur)[0] && count < K) {
                        value[(*cur)[1]] = min(value[(*cur)[1]], value[(*cur)[0]] + (*cur)[2]);
                        indegree.push((*cur)[1]);
                        flights.erase(cur);
                    } else if (cur_src == (*cur)[0] && dst == (*cur)[1]) {
                        value[(*cur)[1]] = min(value[(*cur)[1]], value[(*cur)[0]] + (*cur)[2]);
                        flights.erase(cur);
                    } else {
                        cur++;
                    }
                }
            }
            count++;
        }
        return value[dst] == INT_MAX ? -1 : value[dst];
    }
}; */

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(n, vector<int>(K+1, INT_MAX));
        for (int i = 0; i <= K; i++)
            dp[src][i] = 0;
        for (vector<int> cur : flights) {
            if (cur[0] == src) {
                dp[cur[1]][0] = cur[2];
            }
        }

        for (int i = 1; i <= K; i++) {
            int begin = 0, end = 0;
            for (vector<int> cur : flights) {
                begin = cur[0];
                end = cur[1];
                if (dp[begin][i-1] != INT_MAX)
                    dp[end][i] = min(dp[begin][i-1] + cur[2], dp[end][i]);
            }
        }

        return dp[dst][K] == INT_MAX ? -1 : dp[dst][K];
    }
};