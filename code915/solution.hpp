#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int left = 0;
        int idx = 0;
        int max_left = A[0], cur_max = A[0];
        for (int i = 1; i<A.size(); i++){
            if (A[i] >= cur_max)
                cur_max = A[i];
            if (A[i] < max_left){
                idx = i;
                max_left = cur_max;
            }
        }
        return idx+1;
    }
};