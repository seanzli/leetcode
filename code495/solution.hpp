#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0;
        for (int i = 1; i < timeSeries.size(); ++i) {
            if (timeSeries[i] - timeSeries[i - 1] < duration)
                res += timeSeries[i] - timeSeries[i - 1];
            else
                res += duration;
        }
        res += duration;
        return res;
    }
};