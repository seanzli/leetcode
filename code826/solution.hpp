#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> vec; // profit - word
        int n = difficulty.size();
        for (int i = 0; i < n; i++)
            vec.push_back(make_pair(profit[i], difficulty[i]));
        sort(vec.begin(), vec.end(), [](const auto &a, const auto & b) {
            return a.first > b.first || a.first == b.first && a.second < b.second;
        });

        int profit_sum = 0;
        for (int idx = worker.size() - 1; idx >= 0; idx--) {
            for (int i = 0; i < n; i++) {
                if (worker[idx] >= vec[i].second) {
                    profit_sum += vec[i].first;
                    break;
                }
            }
        }
        return profit_sum;
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        vector<vector<int>> diffprofit;

        for (int i = 0; i<profit.size(); i++){
            diffprofit.push_back({difficulty[i], profit[i]});
        }

        sort(diffprofit.begin(), diffprofit.end());
        sort(worker.begin(), worker.end());

        int i(0), max_profit(0), ans(0);
        for (int j = 0; j<worker.size(); j++){
            while (i < diffprofit.size() && diffprofit[i][0] <= worker[j]){
                max_profit = max(max_profit, diffprofit[i][1]);
                i++;
            }
            ans += max_profit;
        }
        return ans;
    }
};