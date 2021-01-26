
#include "../code238/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();
    vector<int> in = {1,2,3,4};

    vector<int> out = test->productExceptSelf(in);

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}