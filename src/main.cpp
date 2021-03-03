
#include "../code854/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string a = "aabbccddee", b = "dcacbedbae";
    test->kSimilarity(a,b);
    return 0;
}