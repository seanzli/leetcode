#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool helper(string& num, long pre_a, long pre_b, int idx, int count) {
        if (idx >= num.size()) {
            return count > 2;
        }
        long val = 0;
        for (int i = idx; i < num.size(); i++) {
            bool flag = false;
            if (val > pow(10, 17)) {
                break;
            }
            val = val * 10 + num[i] - '0';
            if (count < 2 || pre_a + pre_b == val) {
                flag = helper(num, pre_b, val, i + 1, count + 1);
            }
            if (flag) {
                return true;
            }
            if (val == 0) {
                break;
            }
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        return helper(num, 0, 0, 0, 0);
    }
};