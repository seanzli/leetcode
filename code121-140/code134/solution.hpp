#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <algorithm>
#include <regex>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int cur_gas = gas[0];
        for (int i=0; i<n ;i++)
        {
            if (startWith(i,gas, cost))
                return i;
        }
        return -1;
    }
    bool startWith(int start_idx , vector<int>& gas, vector<int>& cost){
        int n = gas.size();
        int cur_idx = start_idx;
        int cur_gas = 0;
        for (int i = 0; i < n; i++)
        {
            if (gotoNext(gas, cost, cur_idx,cur_gas))
                cur_idx = (cur_idx==n)?0:cur_idx;
            else
                return false;
        }
        if (cur_idx == start_idx)
            return true;
        else
            return false;
    }
    bool gotoNext(vector<int>& gas, vector<int>& cost,int &cur_idx, int &cur_gas){
        cur_gas += gas[cur_idx];
        cur_gas -= cost[cur_idx];
        if (cur_gas < 0)
            return false;
        cur_idx++;
        return true;
    }
};