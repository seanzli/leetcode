
#include "../code40/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    vector <int> nums = {10,1,2,7,6,1,5};

    vector<vector<int>> out  = test->combinationSum2(nums, 8);

    for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << ",";
        }
        cout << endl;        
    }
    

    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}