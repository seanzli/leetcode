
#include "../code658/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    
    vector<int> in = {1,2,3,4,5};
    test->findClosestElements(in,4,3);

    return 0;
}