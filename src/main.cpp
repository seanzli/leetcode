
#include "../code468/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    string in = "192.0.0.1";
    cout << test->validIPAddress(in) << endl;

    return 0;
}