#include <vector>

using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count = 0;
        for (auto& itr : nums) {
            if (itr == 0)
                return 0;
            if (itr < 0)
                ++count;
        }
        return count & 0x1 ? -1 : 1;
    }
};