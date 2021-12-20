#include <vector>

using namespace std;

//class Solution {
//public:
//    int findRadius(vector<int>& houses, vector<int>& heaters) {
//        vector<int> distance(houses.size(), INT_MAX);
//        for (size_t i = 0; i < houses.size(); ++i)
//        {
//            for (size_t j = 0; j < heaters.size(); ++j) {
//                distance[i] = min(distance[i], abs(heaters[j] - houses[i]));
//            }
//        }
//        return *max_element(distance.begin(), distance.end());
//    }
//};

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int res = 0;
        int left_idx = 0, right_idx = 1;
        for (int house : houses)
        {
            int cur = INT_MAX;
            if (house < heaters[left_idx])
                cur = heaters[left_idx] - house;
            else {
                while (right_idx < heaters.size() && heaters[right_idx] < house) {
                    ++left_idx;
                    ++right_idx;
                }
                cur = abs(house - heaters[left_idx]);
                if (right_idx < heaters.size()) {
                    cur = min(cur, abs(house - heaters[right_idx]));
                }
            }
            res = max(res, cur);
        }
        return res;
    }
};