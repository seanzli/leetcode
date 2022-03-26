#include <numeric>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> s;
        for (int i = 0; i < ops.size(); ++i) {
            if (ops[i] == "+" && s.size() > 1)
                s.emplace_back(s[s.size() - 2] + s[s.size() - 1]);
            else if (ops[i] == "C" && !s.empty())
                s.pop_back();
            else if (ops[i] == "D" && !s.empty())
                s.emplace_back(s.back() * 2);
            else
                s.emplace_back(stoi(ops[i]));
        }
        return accumulate(s.begin(), s.end(), 0);
    }
};