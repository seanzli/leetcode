
#include "../code752/solution.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    
    vector<string> d = {"0201","0101","0102","1212","2002"};

    cout << test->openLock(d, "0202") << endl;
    
    return 0;
}