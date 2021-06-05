
#include "../code523/solution.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    
    vector<int> head = {23,2,6,4,7};
    int k = 13;
    cout << test->checkSubarraySum(head, k) << endl;
    
    return 0;
}