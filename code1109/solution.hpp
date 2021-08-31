#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        vector<int> diff(n + 1, 0);
        for (vector<int> cur : bookings) {
            diff[cur[0] - 1] += cur[2];
            diff[cur[1]] -= cur[2];
        }

        res[0] = diff[0];
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        for (vector<int> cur : bookings) {
            res[cur[0] - 1] += cur[2];
            if (cur[1] < n)
                res[cur[1]] -= cur[2];
        }

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] + res[i];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        vector<int> dif(n + 1, 0);
        for (vector<int>& vec : bookings) {
            dif[vec[0] - 1] += vec[2];
            dif[vec[1]] -= vec[2];
        }
        res[0] = dif[0];
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1] + dif[i];
        }
        return res;
    }
};