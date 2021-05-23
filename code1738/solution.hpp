#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        int n_row = matrix.size();
        int n_col = matrix[0].size();
        vector<vector<int>> pre(n_row + 1, vector<int>(n_col + 1));
        for (int i = 0; i < n_row; i++) {
            for (int j = 0; j < n_col; j++) {
                pre[i + 1][j + 1] = pre[i][j + 1] ^ pre[i + 1][j] ^ pre[i][j] ^ matrix[i][j];
                que.push(pre[i + 1][j + 1]);
                if (que.size() > k)
                    que.pop();
            }
        }
        return que.top();
    }
};