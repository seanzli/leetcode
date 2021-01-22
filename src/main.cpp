
#include "../code209/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<char>> grid = {
        {'1','1','0','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
    };

    vector<int> in = {2,3,1,2,4,3};
    cout << test->minSubArrayLen(7,in) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}