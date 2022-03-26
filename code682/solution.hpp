#include <numeric>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> s;
        for (auto & op : ops) {
            if (op == "+" && s.size() > 1)
                s.emplace_back(s[s.size() - 2] + s[s.size() - 1]);
            else if (op == "C" && !s.empty())
                s.pop_back();
            else if (op == "D" && !s.empty())
                s.emplace_back(s.back() * 2);
            else
                s.emplace_back(stoi(op));
        }
        return accumulate(s.begin(), s.end(), 0);
    }
};