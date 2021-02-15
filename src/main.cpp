
#include "../code718/solution.hpp"

#include <queue>

int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    
    vector<int> A = {1,2,3,2,1};
    vector<int> B = {3,2,1,4,7};
    cout<<test->findLength(A,B) << endl;
    return 0;
}