#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        int num = 0.05 * arr.size();
        sort(arr.begin(), arr.end());
        double sum = accumulate(arr.begin() + num, arr.end() - num, 0.0);
        return sum / (arr.size() - num * 2);
    }
};