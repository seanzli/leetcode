
#include "../code200/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<char>> grid = {
        {'1','1','0','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'},
    };

    cout << test->numIslands(grid) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}