
#include "../code126/solution.hpp"

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
    //vector<vector<int>> in = {{2},{3,4},{6,5,7},{4,1,8,3}};
    //vector<int> in = {3,3,5,0,0,3,1,4};

    vector<string> wordLists= {"hot","dot","dog","lot","log","cog"};
    string begin = "hit", end = "cog";
    vector<vector<string>> out = test->findLadders(begin, end, wordLists);

    for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << ",";
        }
        cout << endl;
    }
    
/*     while (out)
    {
        cout << out->val << "->" ;
        out = out->next;
    }
    cout << endl; */

    return 0;
}