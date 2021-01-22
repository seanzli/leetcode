
#include "../code213/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> in = {2,3,2};
    cout << test->rob(in) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}