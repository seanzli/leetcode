
#include "../code473/solution.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    
    vector<int> match = {5,5,5,5,4,4,4,4,3,3,3,3};

    cout << test->makesquare(match) << endl;
    
    return 0;
}