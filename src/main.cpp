
#include "../code218/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string l = "Ah71752";
    vector<vector<int>> in = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    test->getSkyline(in);

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}