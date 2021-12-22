#include <string>

using namespace std;

class Solution {
    int count = 0;
public:
    int repeatedStringMatch(const string& a, const string& b) {
        if (a.find(b) != string::npos)
            return 1;
        string cur = a + a;
        if (cur.find(b) != string::npos)
            return 2;

        size_t idx = b.find(a);
        if (idx == string::npos)
            return -1;
        if (!backward(a,b,a.size() - 1, idx - 1))
            return -1;
        if (!forward(a, b, 0, idx))
            return -1;
        return count;
    }

    bool backward(const string& a, const string& b, size_t i, size_t j) {
        if (j > b.size()) {
            if (i != a.size() - 1)
                ++count;
            return true;
        }
        if (i > a.size()) {
            i = a.size() - 1;
            ++count;
        }
        return a[i] == b[j] && backward(a,b,i-1,j-1);
    }
    bool forward(const string& a, const string& b, size_t i, size_t j) {
        if (j == b.size()) {
            if (i > 0)
                ++count;
            return true;
        }
        if (i == a.size()) {
            i = 0;
            ++count;
        }
        return a[i] == b[j] && forward(a, b, i + 1, j + 1);
    }
};