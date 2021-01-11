
#include "../code88/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    vector<int> nums1 = {2,0};
    vector<int> nums2 = {1};

    test->merge(nums1, 1, nums2, 1);
    for (int i = 0; i < 2; i++)
    {
        cout << nums1[i] << ",";
    }
    cout << endl;
    


    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}