
#include "../code221/solution.hpp"



int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    string l = "Ah71752";
    vector<vector<char>> in =  {{'1','0','1','0','0'},
                                {'1','0','1','1','1'},
                                {'1','1','1','1','1'},
                                {'1','0','0','1','0'}};
    cout << test->maximalSquare(in) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}