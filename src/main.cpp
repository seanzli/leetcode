
#include "../code241/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    vector<int> in = {1,3,-1,-3,5,3,6,7};

    vector<int> out = test->diffWaysToCompute("2-1-1");

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}