#include <vector>

using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> val(k, 1);
        int idx3 = 0, idx5 = 0, idx7 = 0;
        int i = 1;
        while (i < k) {
            val[i] = min(min(val[idx3] * 3, val[idx5] * 5), val[idx7] * 7);
            if (val[i] == val[idx3] * 3)
                ++idx3;
            if (val[i] == val[idx5] * 5)
                ++idx5;
            if (val[i] == val[idx7] * 7)
                ++idx7;
            ++i;
        }
        return val.back();
    }
};