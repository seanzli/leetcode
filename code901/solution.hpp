#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* class StockSpanner {
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
 */

class StockSpanner {
    stack<pair<int, int>> st; //large -> small  price / day
    int cur_day = 0;
public:
    StockSpanner() {
        st.push(make_pair(INT_MAX, 0));
    }
    
    int next(int price) {
        int dif_day = 1;
        cur_day++;
        while (st.top().first <= price) {
            st.pop();
        }
        dif_day = cur_day - st.top().second;
        st.push(make_pair(price, cur_day));
        return dif_day;
    }
};