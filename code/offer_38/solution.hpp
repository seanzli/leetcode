#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

/* class Solution {
    vector<string> res;
    string cur;
    vector<bool> visited;
    set<string> st;
public:
    vector<string> permutation(string s) {
        int n = s.size();
        sort(s.begin(), s.end());
        visited = vector<bool>(n, false);
        dfs(s, 0);
        return res;
    }

    void dfs(string s, int idx) {
        if (idx == s.size()) {
            if (st.find(cur) != st.end())
                return;
            st.insert(cur);
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (visited[i] == false) {
                cur += s[i];
                visited[i] = true;
                dfs(s, idx + 1);
                visited[i] = false;
                cur.pop_back();
            }
        }
        return;
    }
}; */

class Solution {
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }
private:
    vector<string> res;
    void dfs(string s, int x) {
        if(x == s.size() - 1) {
            res.push_back(s);                       // 添加排列方案
            return;
        }
        set<int> st;
        for(int i = x; i < s.size(); i++) {
            if(st.find(s[i]) != st.end()) continue; // 重复，因此剪枝
            st.insert(s[i]);
            swap(s[i], s[x]);                       // 交换，将 s[i] 固定在第 x 位
            dfs(s, x + 1);                          // 开启固定第 x + 1 位字符
            swap(s[i], s[x]);                       // 恢复交换
        }
    }
};