#include "../code682/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution s;
    vector<string> ops = {"5","2","C","D","+"};
    std::cout << s.calPoints(ops) << std::endl;
    return 0;
}