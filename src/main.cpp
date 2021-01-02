
#include "../code7/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    //int num = atoi(argv[1]);
    int num = 2147483647;//atoi(argv[2]);
    cout << test->reverse(num) << endl;

    return 0;
}