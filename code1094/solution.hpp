#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> p(1002,0);
        for (int i = 0; i < trips.size(); i++){
            for (int j = trips[i][1]; j<trips[i][2]; j++)
                p[j] += trips[i][0];
        }
        for (int i = 0; i < p.size(); i++){
            if (p[i] > capacity)
                return false;
        }
        return true;
    }
};