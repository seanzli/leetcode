
#include "../code1162/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
    test->maxDistance(grid);
    
    return 0;
}