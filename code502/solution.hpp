#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int cur = 0;
        priority_queue<int, vector<int>, ::less<int>> que;
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; ++i) {
            arr.push_back({capital[i], profits[i]});
        }

        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) {
            while (cur < n && arr[cur].first <= w) {
                que.push(arr[cur].second);
                cur++;
            }
            if (!que.empty()) {
                w += que.top();
                que.pop();
            } else {
                break;
            }
        }
        return w;
    }
};