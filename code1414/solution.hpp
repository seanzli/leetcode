#include <vector>

using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> mem;
        mem.push_back(1);
        int k1 = 1, k2 = 1;
        while (k1 + k2 <= k) {
            int k3 = k1 + k2;
            k2 = k3;
            k1 = k2;
            mem.push_back(k3);
        }

        int res = 0;
        while (k != 0) {
            int left = 0, right = mem.size() - 1;
            while (left < right) {
                int mid = (right + left + 1) >> 1;
                if (mem[mid] <= k)
                    left = mid;
                else
                    right = mid - 1;
            }
            k -= mem[right];
            ++res;
        }
        return res;
    }
};