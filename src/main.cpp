
#include "../code1389/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {4,2,4,3,2};
    vector<int> index = {0,0,1,3,1};
    test->createTargetArray(in,index);// << endl;


    return 0;
}