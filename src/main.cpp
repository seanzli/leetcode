
#include "../code13/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = argv[1];

    cout <<test->romanToInt(s)<<endl;

    return 0;
}