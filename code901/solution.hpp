#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class StockSpanner {
public:
    StockSpanner() {

    }
    
    int next(int price) {
        int count = 0;
        while (!stk.empty() && price >= prices[stk.top()]) {
            stk.pop();
        }
        count = stk.empty() ? prices.size() + 1 : prices.size() - stk.top();
        prices.push_back(price);
        stk.push(prices.size() - 1);
        return count;
    }

private:
    vector<int> prices;
    stack<int> stk;
};
