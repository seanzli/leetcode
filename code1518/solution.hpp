#include <iostream>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int res_empty_bottle = numBottles;
        while (res_empty_bottle >= numExchange) {
            int exchange = res_empty_bottle / numExchange;
            res_empty_bottle = res_empty_bottle - exchange * numExchange;
            res += exchange;
            res_empty_bottle += exchange;
        }
        return res;
    }
};