#include <string>

using namespace std;

class Solution {
public:
    string reformatNumber(string number) {
        string res = "";
        string cur = "";
        for (int i = 0; i < number.size(); ++i) {
            if ('0' <= number[i] && number[i] <= '9') {
                cur += number[i];
                if (cur.size() == 3) {
                    res += cur + "-";
                    cur = "";
                }
            }
        }
        if (cur.size() == 2)
            res += cur;
        else if (cur.size() == 1) {
            res.pop_back();
            cur = res.back() + cur;
            res.pop_back();
            res += std::string("-") + cur;
        } else if (cur.empty())
            res.pop_back();
        return res;
    }
};