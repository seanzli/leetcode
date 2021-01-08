
#include "../code61/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    //ListNode *node = new ListNode(1, new ListNode(2,new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *node = new ListNode();
    ListNode *out =  test->rotateRight(nullptr,4);

    while (out!=nullptr)
    {
        cout << out->val << "->";
        out = out->next;
    }
    cout << endl;

/*     for (int i = 0; i < out.size(); i++)
    {
        //cout << "/////" << endl;
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << "," ; 
        }
        cout << endl;
    }  */
    
    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}
