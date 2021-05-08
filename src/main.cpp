
#include "../code1128/solution.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<int>> dom = {{1,2},{1,2},{1,1},{1,2},{2,2}};
    
    cout << test->numEquivDominoPairs(dom) << endl;
    return 0;
}