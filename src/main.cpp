
#include "../code239/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    vector<int> in = {1,3,-1,-3,5,3,6,7};

    vector<int> out = test->maxSlidingWindow(in,3);

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}