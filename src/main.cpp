
#include "../code697/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {1, 2, 2, 3, 1};
    test->findShortestSubArray(in);
    
    return 0;
}