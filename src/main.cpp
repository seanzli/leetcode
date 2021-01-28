
#include "../code289/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<int>> in = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    test->gameOfLife(in);

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}