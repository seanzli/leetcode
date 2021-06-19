
#include "../code1239/solution.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    
    vector<string> arr = {"cha","r","act","ers"};

    cout << test->maxLength(arr) << endl;
    
    return 0;
}