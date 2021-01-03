
#include "../code12/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    int num = atoi(argv[1]);

    cout <<test->intToRoman(num)<<endl;

    return 0;
}