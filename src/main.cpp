
#include "../code307/solution.hpp"

int main(int argc, char* argv[])
{
    //Solution *test = new Solution();
    vector<int> in = {-1};
    NumArray *test = new NumArray(in);
    cout << test->sumRange(0,0) << endl;
    test->update(0,1);
    cout << test->sumRange(0,0) << endl;


    //cout << test->isAdditiveNumber("199001200") << endl;
    
    //cout << test->getHint(secret, guess) << endl;

    /* while (in){
        cout << in->val << "->";
        in = in->next;
    }
    cout << endl; */
    return 0;
}