#include <vector>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)
            return false;
        int sum = 1;
        for (int i = 2; i <= num / i; ++i) {
            int cur = num / i;
            if (num == cur * i) {
                sum += cur;
                if (i != cur)
                    sum += i;
            }
        }
        return sum == num;
    }
};