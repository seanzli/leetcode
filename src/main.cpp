
#include "../code393/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> data = {250,145,145,145,145};
    cout << test->validUtf8(data) << endl;
    return 0;
}