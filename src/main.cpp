
#include "../code290/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string pattern = "abba";
    string s = "dog dog dog dog";
    //vector<vector<int>> in = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    cout << test->wordPattern(pattern, s) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}