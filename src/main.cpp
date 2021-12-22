#include "../code686/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution s;
//    string a = "abcd";
//    string b = "cdabcdab";
string a = "bb";
string b = "bbbbbbb";
    std::cout << s.repeatedStringMatch(a, b) << std::endl;
    return 0;
}