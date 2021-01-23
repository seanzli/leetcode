
#include "../code/code08_13/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<vector<int>> in = {{1, 1, 1}, {2, 3, 4}, {2, 6, 7}, {3, 4, 5}};
    cout << test->pileBox(in) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}