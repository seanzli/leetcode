#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() <= 2 || heightMap[0].size() <= 2)
            return 0;
        int m = heightMap.size();
        int n = heightMap[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> que;
        vector<vector<bool>> visit(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    que.push({heightMap[i][j], i * n + j});
                    visit[i][j] = true;
                }
            }
        }

        int res = 0;
        int dirs[] = {-1, 0, 1, 0, -1};
        while (!que.empty()) {
            pair<int, int> cur = que.top(); que.pop();
            for (int k = 0; k < 4; ++k) {
                int nx = cur.second / n + dirs[k];
                int ny = cur.second % n + dirs[k + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
                    if (heightMap[nx][ny] < cur.first)
                        res += cur.first - heightMap[nx][ny];
                    visit[nx][ny] = true;
                    que.push({max(heightMap[nx][ny], cur.first), nx * n + ny});
                }
            }
        }

        return res;
    }
};