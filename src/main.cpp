// #include "../code1-100/code41-60/code58/solution.hpp"
#include "../code475/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> house = {282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923};
    vector<int> heater = {823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612};
    std::cout << s.findRadius(house, heater) << std::endl;
    
    return 0;
}