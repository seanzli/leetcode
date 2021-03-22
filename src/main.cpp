
#include "../code331/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string in = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    test->isValidSerialization(in);
    return 0;
}