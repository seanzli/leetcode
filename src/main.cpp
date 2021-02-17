
#include "../code566/solution.hpp"

#include <queue>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<int>> in = {{1,2},{3,4}};
    test->matrixReshape(in, 4, 1);
    
    return 0;
}