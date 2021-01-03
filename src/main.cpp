
#include "../code14/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<string> strs = {"reflower","flow","flight"};

    cout <<test->longestCommonPrefix(strs)<<endl;

    return 0;
}