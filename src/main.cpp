
#include "../code1652/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> code = {5,7,1,4};
    test->decrypt(code, -3);
    return 0;
}