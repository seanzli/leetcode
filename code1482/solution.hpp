#include <vector>
#include <algorithm>

using namespace std;

/* class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < m*k)
            return -1;
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(bloomDay, mid, m, k))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
        
    }
    bool valid(vector<int>&bloomDay, int day, int m, int k) {
        int count_m = 0, count_k = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                count_k++; // serial k
                if (count_k == k) {
                    count_m++; // count m
                    if (count_m == m)
                        return true;
                    count_k == 0;
                }
            } else {
                count_k = 0;
            }
        }
        return false;
    }
}; */

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (k * m > bloomDay.size()) {
            return -1;
        }
        int low = 1, high = 1;
        int length = bloomDay.size();
        for (int i = 0; i < length; i++) {
            high = max(high, bloomDay[i]);
        }
        while (low < high) {
            int days = (high - low) / 2 + low;
            if (canMake(bloomDay, days, m, k)) {
                high = days;
            } else {
                low = days + 1;
            }
        }
        return low;
    }

    bool canMake(vector<int>& bloomDay, int days, int m, int k) {
        int bouquets = 0;
        int flowers = 0;
        int length = bloomDay.size();
        for (int i = 0; i < length && bouquets < m; i++) {
            if (bloomDay[i] <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
};