#include "../code201-220/code207/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution s;
    vector<vector<int>> prerequisites = 
    {{0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4}};
    std::cout << s.canFinish(20, prerequisites) << std::endl;
    return 0;
}