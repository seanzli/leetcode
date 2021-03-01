
#include "../code394/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string in = "2[abc]3[cd]ef";
    test->decodeString(in);
    return 0;
}