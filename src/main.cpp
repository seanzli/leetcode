
#include "../code826/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> dif = {2,4,6,8,10};
    vector<int> profit = {10,20,30,40,50};
    vector<int> worker = {4,5,6,7};
    test->maxProfitAssignment(dif, profit, worker);
    return 0;
}