#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        std::vector<int> count(26, 0);
        std::vector<int> dif;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != goal[i])
                dif.push_back(i);
            ++count[s[i] - 'a'];
        }
        if (dif.size() == 2) {
            if (s[dif[0]] == goal[dif[1]] &&
                s[dif[1]] == goal[dif[0]])
                return true;
            return false;
        }
        if (dif.size() == 0) {
            for (int i = 0; i < count.size(); ++i) {
                if (count[i] > 1)
                    return true;
            }
        }
        return false;
    }
};