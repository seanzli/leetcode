
#include "../code832/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<int>> in = {{1,1,0},{1,0,1},{0,0,0}};
    test->flipAndInvertImage(in);
    
    return 0;
}