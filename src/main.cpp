#include "../code201-220/code219/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> num = {1,2,3,4,5,6,7,8,9,10};
    std::cout << s.containsNearbyDuplicate(num, 15) << std::endl;
    return 0;
}