#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int res = 0;
        unordered_set<string> hash;
        for (string itr : deadends)
            hash.insert(itr);

        queue<string> que;
        que.push("0000");
        while (que.size()) {
            int n = que.size();
            for (int i = 0; i < n; i++) {
                string itr = que.front(); que.pop();
                if (itr == target)
                    return res;
                if (hash.count(itr))
                    continue;
                hash.insert(itr);
                for (int iChar = 0; iChar < 4; ++iChar) {
                    if (itr[iChar] < '9') {
                        itr[iChar]++;
                        if (hash.count(itr) == 0)
                            que.push(itr);
                        itr[iChar]--;
                    } else {
                        itr[iChar] = '0';
                        if (hash.count(itr) == 0)
                            que.push(itr);
                        itr[iChar] = '9';
                    }

                    if (itr[iChar] > '0') {
                        itr[iChar]--;
                        if (hash.count(itr) == 0)
                            que.push(itr);
                        itr[iChar]++;
                    } else {
                        itr[iChar] = '9';
                        if (hash.count(itr) == 0)
                            que.push(itr);
                        itr[iChar] = '0';
                    }
                }
            }
            res++;
        }
        return -1;
    }
};