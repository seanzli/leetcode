#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> visited; // num, count
        int sum = 0;
        for (const auto& itr : nums) {
            ++visited[itr];
            if (visited[itr] == 1) {
                sum += itr;
            } else if (visited[itr] == 2) {
                sum -= itr;
            }
        }
        return sum;
    }
};