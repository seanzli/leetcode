
#include "../code1004/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> A = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << test->longestOnes(A, 3) << endl;
    
    return 0;
}