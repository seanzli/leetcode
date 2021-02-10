
#include "../code1424/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    
    vector<vector<int>> in = {{1,2,3},{4,5,6},{7,8,9}};
    test->findDiagonalOrder(in);

    return 0;
}