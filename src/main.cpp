
#include "../code/LC/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> s = {1, 1, -2, 6};

    cout << test->increasingTriplet(s) << endl;

    return 0;
}