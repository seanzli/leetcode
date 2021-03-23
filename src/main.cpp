
#include "../code880/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "leet2code3";
    cout << test->decodeAtIndex(s, 10) << endl;
    return 0;
}