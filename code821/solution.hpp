#include <string>
#include <vector>

using namespace std;

static const size_t MAX_L = 10000;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        size_t size = s.size();
        vector<int> res(size, MAX_L);

        if (s[0] == c)
            res[0] = 0;

        for (size_t i = 1; i < size; ++i) {
            if (s[i] == c)
                res[i] = 0;
            else
                res[i] = min(res[i], res[i - 1] + 1);
        }

        for (size_t i = size - 1; i > 0; --i) {
            res[i] = min(res[i], res[i + 1] + 1);
        }

        if (size > 1)
            res[0] = min(res[0], res[1]);
        return res;
    }
};