
#include "../code174/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<int>> in = {{1,-3,3},{0,-2,0},{-3,-3,-3}};

    cout << test->calculateMinimumHP(in) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}