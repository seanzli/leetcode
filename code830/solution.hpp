#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int left = 0, right = 0;
        while (right < s.size()) {
            while (right < s.size() && s[left] == s[right])
                right++;
            if (right - left > 2) {
                res.push_back({left, right - 1});
            }
            left = right;
        }
        if (right - left > 2) {
            res.push_back({left, right - 1});
        }
        return res;
    }
};