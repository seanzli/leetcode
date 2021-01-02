
#include "../code8/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "-91283472332";//argv[1];
    //int num = 2147483647;//atoi(argv[2]);
    cout << test->myAtoi(s) << endl;

    return 0;
}