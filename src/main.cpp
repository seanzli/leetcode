
#include "../code593/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> p1 = {1,1};
    vector<int> p2 = {0,1};
    vector<int> p3 = {1,2};
    vector<int> p4 = {0,0};
    test->validSquare(p1,p2,p3,p4);
    
    return 0;
}