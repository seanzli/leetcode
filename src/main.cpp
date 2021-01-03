
#include "../code20/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string str = "()[]}";
    cout << test->isValid(str) << endl;

    return 0;
}