
#include "../code1028/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "1-2--3--4-5--6--7";
    cout << test->recoverFromPreorder(s) << endl;
    return 0;
}