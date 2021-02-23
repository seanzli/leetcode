
#include "../code1052/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> cus = {1,0,1,2,1,1,7,5};
    vector<int> gru = {0,1,0,1,0,1,0,1};
    test->maxSatisfied(cus, gru, 3);
    
    return 0;
}