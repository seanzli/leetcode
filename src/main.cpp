
#include "../code134/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> gas = {2,3,4};
    vector<int> cost = {3,4,3};

    cout << test->canCompleteCircuit(gas, cost) << endl;

/*     for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << ",";
        }
        cout << endl;
    } */
    return 0;
}