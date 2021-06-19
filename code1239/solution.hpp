#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/* class Solution {
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
}; */

class Solution {
    int res;
public:
    int maxLength(vector<string>& arr) {
        vector<bool> visited(26, false);
        
        sort(arr.begin(), arr.end(), [](const string& a, const string &b) {return a.size() > b.size();});
        
        if (arr.size() == 0)
            return 0;

        dfs(arr, 0, visited, 0);

        return res;
    }

    void dfs(const vector<string>& strs, int i, vector<bool>& visited, int len) {
        if (i == strs.size()) {
            return;
        }

        for (; i < strs.size(); i++) {
            vector<bool> v = visited;
            bool flag = true;
            for (char itr : strs[i]) {
                if (v[itr - 'a'] == true) {
                    flag = false;
                    break;
                }
                v[itr - 'a'] = true;
            }
            if (flag) {
                res = max(res, len + (int)strs[i].size());
                dfs(strs, i + 1, v, len + strs[i].size());
            }
        }
        return;
    }
};