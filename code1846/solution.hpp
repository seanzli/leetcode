#include <vector>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int max_value = 1;
        arr[0] = 1;
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
            max_value = max(max_value, arr[i]);
        }
        return max_value;
    }
};