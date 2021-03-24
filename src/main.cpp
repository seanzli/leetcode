
#include "../code394/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "3[a]2[bc]";
    cout << test->decodeString(s) << endl;
    return 0;
}