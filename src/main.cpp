
#include "../code80/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    //string in = "+3. e04116";
    //vector<vector<int>> in = {{1,2,3},{4,5,6}};//,{4,2,1}};
    //vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    
    //vector<vector<char>> in = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    /* vector<vector<char>> in = {{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    string word = "AAB"; */
    vector<int> nums = {1};
    cout << test->removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ",";
    }
    cout <<endl;
    
 /*    while (out!=nullptr)
    {
        cout << out->val << "->";
        out = out->next;
    }
    cout << endl; */

/*      for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i][j] << ",";
        }
        cout << endl; 
    } */
     
    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}
/* ["Science   is what we","understand      well","enough to explain to","a   computer. Art is","everything  else  we","do                  "]
   ["Science  is  what we","understand      well","enough to explain to","a  computer.  Art is","everything  else  we","do                  "] */