
#include "../code318/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<string> in = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << test->maxProduct(in) << endl;
    return 0;
}