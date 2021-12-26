#include "../code1078/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution s;
    string text = "alice is a good girl she is a good student";
    string first = "a";
    string second = "good";
    s.findOcurrences(text, first, second);
    return 0;
}