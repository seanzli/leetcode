
#include "../code6/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string s = "AB";//argv[1];
    int num = 4;//atoi(argv[2]);
    cout << test->convert(s,num) << endl;

    return 0;
}