
#include "../code92/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

    vector<int> nums1 = {1,2,3,4,5};
    ListNode *in = new ListNode(nums1[0]);
    ListNode *cur = nullptr;
    cur = in;
    for (int i = 1; i< nums1.size(); ++i)
    {
        cur->next = new ListNode(nums1[i]);
        cur = cur->next;
    }
    //ListNode *in = new ListNode(1,new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    
    ListNode *out = test->reverseBetween(in, 1,2);

    while (out)
    {
        cout << out->val << "->" ;
        out = out->next;
    }
    cout << endl;

    return 0;
}