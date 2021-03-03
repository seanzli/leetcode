#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
private:
    string target;
    int n;
    static bool func(pair<int, string> a, pair<int, string> b) {
        return a.first > b.first;
    }

public:
    int kSimilarity(string A, string B) {
        target = B;
        int count = 0;
        n = A.size();
        if (n != B.size())
            return -1;
        int dis_a = distanceString(A);
        if (dis_a == 0)
            return 0;
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(&func)> que(func);
        set<string> m_set;
        que.push(make_pair(dis_a, A));
        while (que.size()) {
            auto itr = que.top();
            string cur = itr.second;
            int cur_dis = itr.first;
            que.pop();
            if (m_set.count(cur) == 1)
                continue;
            m_set.insert(cur);
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    string tmp = cur;
                    swap(tmp[i], tmp[j]);
                    int tmp_dis = distanceString(tmp);
                    if (tmp_dis == 0)   
                        return count + 1;
                    if (m_set.count(tmp) == 1)
                        continue;
                    que.push(make_pair(tmp_dis, tmp));
                }
            }
            count++;
        }
        return -1;
    }
    int distanceString(const string &a) {
        int dis = 0;
        for (int i = 0; i < n; i++) {
            dis += abs(a[i] - target[i]);
        }
        return dis;
    }
};

class Solution {
public:
    int kSimilarity(string A, string B) {
        unordered_set<string> history;
        queue<pair<string, int>> poss;
        history.insert(A);
        poss.push({A, 0});

        if (A == B) {
            return 0;
        }

        // forward
        while (poss.size()) {
            // get poss
            string cur = poss.front().first;
            int k = poss.front().second;
            poss.pop();


            // prepare next
            vector<string> holding;
            bool bFind = false;
            for (int i = 0; i < cur.length() - 1; ++i) {
                if (bFind)
                    break;

                if (cur[i] == B[i]) {
                    continue;
                }

                for (int j = i + 1; j < cur.length(); ++j) {
                    if (cur[j] != B[i]) {
                        continue;
                    }

                    if (cur[j] == B[j]) {
                        continue;
                    }

                    string tmp = cur;
                    char mid = tmp[i];
                    tmp[i] = tmp[j];
                    tmp[j] = mid;

                    // conclude
                    if (tmp == B) {
                        return k + 1;
                    }

                    if (history.find(tmp) == history.end()) {
                        history.insert(tmp);
                        if (cur[i] == B[j]) {
                            poss.push({tmp, k + 1});
                            holding.clear();
                            bFind = true;
                            break;
                        }
                        else
                            holding.emplace_back(tmp);
                    }
                }
            }
            for (auto& item: holding) {
                poss.push({item, k + 1});
            }
        }
        return numeric_limits<int>::max();
    }
};