#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        using PII = std::pair<int, int>;
        std::vector<PII> hash(score.size());
        for (int i = 0; i < score.size(); ++i) {
            hash[i] = std::make_pair(score[i], i);
        }
        std::sort(hash.begin(), hash.end(), 
            [](const PII& a, const PII& b) {
                return a.first > b.first;
            }
        );

        vector<string> res(hash.size());
        for (int i = 0; i < hash.size(); ++i) {
            res[hash[i].second] = std::to_string(i + 1);
        }
        res[hash[0].second] = "Gold Medal";
        if (res.size() > 1)
            res[hash[1].second] = "Silver Medal";
        if (res.size() > 2)
            res[hash[2].second] = "Bronze Medal";
        return res;
    }
};