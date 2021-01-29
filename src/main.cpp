
#include "../code667/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();


    vector<int> out = test->constructArray(3,2);

    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << ',';
    }
    cout << endl;

    return 0;
}