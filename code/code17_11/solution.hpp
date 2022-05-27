#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

//class Solution {
//public:
//    int findClosest(vector<string>& words, string word1, string word2) {
//        int idx1 = -1, idx2 = -1;
//        int size = words.size();
//        int res = size;
//        for (int i = 0; i < size; ++i) {
//            if (words[i] == word1)
//                idx1 = i;
//            if (words[i] == word2)
//                idx2 = i;
//            if (idx1 >= 0 && idx2 >= 0)
//                res = min(res, abs(idx1 - idx2));
//        }
//        return res;
//    }
//};

auto _{ []() noexcept
        {
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr); std::cout.tie(nullptr);
            return 0;
        }() };

class Solution {
public:
    int findClosest(vector<string>& words, const string& word1, const string& word2) {
        set<size_t> pos[2];
        for (auto it = words.cbegin();
            (it = find_if(it, words.cend(), [&](auto&& s) { return s == word1 || s == word2; })) < words.cend();
            ++it)
            pos[*it == word2].insert(it - words.cbegin());
        auto ans = words.size();
        auto&& [l, r] = minmax(pos[0], pos[1], [](auto&& a, auto&& b) { return a.size() < b.size(); });
        for (auto& i : l)
        {
            auto tmp = r.upper_bound(i), tmp2 = tmp;
            ans = min(min(ans, *tmp - i), i - *(--tmp2));
            if (tmp == r.cend()) break;
        }
        return ans;
    }
};