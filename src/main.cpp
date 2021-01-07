
#include "../code48/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    string s = "adceb";
    string p = "a*c*b";
    //vector<vector<int>> nums = {{5,1,9,11},
                                //{2,4,8,10},
                                //{13,3,6,7},
                                //{15,14,12,16}};
    //vector<vector<int>> nums = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<vector<int>> nums = {{1}};
    test->rotate(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[i].size(); j++)
        {
            cout << nums[i][j] << ",";
        }
        cout << endl;
    }
    
    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}