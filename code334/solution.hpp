#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, mid = INT_MAX;
        for (const int& itr : nums) {
            if (itr <= left) {
                left = itr;
            } else if (itr <= mid) {
                mid = itr;
            } else if (itr > mid) {
                return true;
            }
        }
        return false;
    }
};