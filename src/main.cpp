
#include "../code115/solution.hpp"

int main(int argc, char* argv[])
{
    Solution *test = new Solution();

/*     vector<int> nums1 = {1,2,3,4,5};
    ListNode *in = new ListNode(nums1[0]);
    ListNode *cur = nullptr;
    cur = in;
    for (int i = 1; i< nums1.size(); ++i)
    {
        cur->next = new ListNode(nums1[i]);
        cur = cur->next;
    } */
    string s1 = "rabbbit";
    string s2 = "rabbit";

    cout << test->numDistinct(s1, s2)<<endl;

/*     for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << endl;
    } */
    
/*     while (out)
    {
        cout << out->val << "->" ;
        out = out->next;
    }
    cout << endl; */

    return 0;
}