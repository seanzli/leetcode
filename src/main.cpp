
#include "../code735/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {-2,-1,1,2};
    test->asteroidCollision(in);
    
    return 0;
}