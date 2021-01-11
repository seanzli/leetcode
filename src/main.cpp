
#include "../code89/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    vector<int> nums1 = {2,0};
    vector<int> nums2 = {1};

    vector<int> out = test->grayCode(2);

    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << ", " << test->dec2bin(out[i]) << endl;
    }
    cout << endl;
    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}