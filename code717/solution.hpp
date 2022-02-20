#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        int n = bits.size(), i = n - 2;
        while (i >= 0 and bits[i]) {
            --i;
        }
        return (n - i) % 2 == 0;
    }
};