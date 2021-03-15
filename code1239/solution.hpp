#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int max_length = 0;
    vector<bool> visited;
    int cur_length = 0;
public:
    int maxLength(vector<string>& arr) {
        visited = vector<bool>(26, false);
        sort(arr.begin(), arr.end(), [](const string& a, const string& b){return a.size() > b.size();});
        dfs(arr, 0);
        return max_length;
    }

    void dfs(vector<string>& arr, int idx) {
        if (idx == arr.size()) {
            return;
        }

        if (max_length == 26)
            return;

        for (int i = idx; i < arr.size(); i++) {
            if (cur_length + arr[i].size() > 26)
                continue;
            if (checkString(arr[i])) {
                for (char cur : arr[i])
                    visited[cur - 'a'] = true;
                cur_length += arr[i].size();
                max_length = max(max_length, cur_length);
                dfs(arr, i + 1);
                for (char cur : arr[i])
                    visited[cur - 'a'] = false;
                cur_length -= arr[i].size();
            }
        }
    }
    bool checkString(const string& str) {
        vector<bool> cur(26, 0);
        for (int i = 0; i < str.size(); i++) {
            if (visited[str[i] - 'a'] == true || cur[str[i] - 'a'] == true)
                return false;
            cur[str[i] - 'a'] = true;
        }
        return true;
    }
};