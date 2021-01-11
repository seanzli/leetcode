
#include "../code85/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

/*     vector<int> nums = {1,1,1,2,2,2,3};
    ListNode *in, *cur = new ListNode(nums[0]), *out;
    in = cur;
    for (int i = 1; i < nums.size(); i++)
    {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    } */
    vector<int> nums = {2,4};
    //vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    //vector<vector<char>> matrix = {{}};
    vector<vector<char>> matrix = {{'0','0','0','0','0','0','1'},{'0','0','0','0','1','1','1'},{'1','1','1','1','1','1','1'},{'0','0','0','1','1','1','1'}};

    
/*     while (out!=nullptr)
    {
        cout << out->val << "->";
        out = out->next;
    }
    cout << endl; */

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << ",";
        }
        cout << endl; 
    } 
    cout << test->maximalRectangle(matrix) << endl;
     
    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}
/* ["Science   is what we","understand      well","enough to explain to","a   computer. Art is","everything  else  we","do                  "]
   ["Science  is  what we","understand      well","enough to explain to","a  computer.  Art is","everything  else  we","do                  "] */