
#include "../code45/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    string s = "adceb";
    string p = "a*c*b";
    vector<int> nums = {2,3,0,1,4};
    cout << test->jump(nums)<<endl;    

    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}