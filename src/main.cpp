
#include "../code/LC/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> s = {3 , 1};

    cout << test->search(s, 1) << endl;

    return 0;
}