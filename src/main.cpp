
#include "../code/LC/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {2,0,2,1,1,0};

    test->sortColors(in);

    for_each(in.begin(), in.end(), [](const int& itr){cout << itr << ",";});
    cout << endl;
    
    return 0;
}