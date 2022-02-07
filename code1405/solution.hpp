#include <vector>
#include <queue>
#include <string>

using namespace std;

//class Solution {
//public:
//    string longestDiverseString(int a, int b, int c) {
//        pair<int, char> pa = make_pair(a, 'a');
//        pair<int, char> pb = make_pair(b, 'b');
//        pair<int, char> pc = make_pair(c, 'c');
//
//        vector<pair<int, char>> vec = {pa, pb, pc};
//        auto sort_pair = [&] {
//            sort(vec.begin(), vec.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
//                return a.first > b.first;
//            });
//        };
//
//        string res = "";
//        while (vec[0].first + vec[1].first + vec[2].first > 0) {
//            sort_pair();
//            if (res.size() < 2) {
//                res.push_back(vec[0].second);
//                --vec[0].first;
//                continue;
//            }
//            char last1 = res.back(), last2 = res[res.size() - 2];
//            if (last1 == last2 && last1 == vec[0].second) {
//                if (vec[1].first > 0) {
//                    res.push_back(vec[1].second);
//                    --vec[1].first;
//                } else {
//                    return res;
//                }
//            } else {
//                res.push_back(vec[0].second);
//                --vec[0].first;
//            }
//        }
//        return res;
//    }
//};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        vector<pair<int, char>> m{{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (1) {
            sort(rbegin(m), rend(m));
            int pre_sz = ans.size();
            for (auto &[cnt, ch] : m) {
                if (cnt == 0 ||
                    ans.size() >= 2 && ch == ans.back() && ch == ans[ans.size() - 2]) continue;
                ans += ch;
                --cnt;
                break;
            }
            if (pre_sz == ans.size()) break;
        }
        return ans;
    }
};