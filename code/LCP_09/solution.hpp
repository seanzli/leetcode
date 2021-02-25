#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minJump(vector<int>& jump) {
        int target = jump.size();
        queue<int> que; // cur-idx
        vector<bool> visited(target, false);
        if (jump[0] == 0)
            return 0;
        que.push(0);
        visited[0] = true;
        int left = 0;
        int count = 0;
        while (que.size()) {
            int n = que.size();
            int max_idx = 0;
            for (int i = 0; i < n; i++) {
                int cur = que.front(); que.pop();
                int can_get = cur + jump[cur];
                if (can_get >= target)
                    return (count + 1);
                visited[cur] = true;
                max_idx = max(max_idx, can_get);
                que.push(can_get + jump[can_get]);
            }
            count++;
            bool move_left = true;
            for (int j = left; j <= max_idx; j++) {
                if (visited[j] == false) {
                    que.push(j);
                    move_left = false;
                }
                if (move_left)
                    left++;
            }
        }
        return count;
    }
};