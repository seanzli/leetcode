
#include "../code1377/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<int>> in = {{2,1},{3,2},{4,1},{5,1},{6,4},{7,1},{8,7}};
    test->frogPosition(8, in, 7, 7);
    return 0;
}