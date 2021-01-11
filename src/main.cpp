
#include "../code86/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    vector<int> nums = {2,1};

    ListNode *in, *cur = new ListNode(nums[0]);
    in = cur;
    for (int i = 1; i < nums.size(); i++)
    {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    cur = in;
    while (cur!=nullptr)
    {
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << endl;
    ListNode* out = test->partition(in,2);

    while(out){
        cout << out->val << "->";
        out = out->next;
    }
    cout << endl;

    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}