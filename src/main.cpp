
#include "../code787/solution.hpp"

#include <queue>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<int>> flights = {{0,1,1},{0,2,5},{1,2,1},{2,3,1},{3,4,1}};
    cout << test->findCheapestPrice(5, flights, 0, 4, 2) << endl;
    
    return 0;
}