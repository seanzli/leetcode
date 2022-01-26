#include <vector>
#include <unordered_map>

using namespace std;

//class Solution {
//public:
//    int findJudge(int n, vector<vector<int>>& trust) {
//        vector<int> count_trust(n + 1);
//        for (auto& itr : trust) {
//            --count_trust[itr[0]]; //trust people
//            ++count_trust[itr[1]]; //
//        }
//
//        for (int i = 0; i < n; ++i) {
//            if (count_trust[i] == n-1)
//                return i;
//        }
//        return -1;
//    }
//};

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1)
            return 1;
        unordered_map<int, vector<int>> hash; // a -> vec(b) : b trust a
        vector<int> num(n+1,0);
        for (const auto& itr : trust) {
            hash[itr[1]].push_back(itr[0]);
            num[itr[0]]++;
        }
        int res = -1;
        for (const auto& itr : hash) {
            if (itr.second.size() == n - 1 && num[itr.first]==0) {
                if (res > 0)
                    return -1;
                else
                    res = itr.first;
            }
        }
        return res;
    }
};