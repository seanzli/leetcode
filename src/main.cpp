
#include "../code1482/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> bl = {1,10,2,9,3,8,4,7,5,6};
    cout << test->minDays(bl, 4, 2) << endl;
    return 0;
}