
#include "../code68/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time;
    start_time = clock();
    Solution *test = new Solution();

    //string in = "+3. e04116";
    //vector<vector<int>> in = {{1,2,3},{4,5,6}};//,{4,2,1}};
    vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> out = test->fullJustify(words,20);

 /*    while (out!=nullptr)
    {
        cout << out->val << "->";
        out = out->next;
    }
    cout << endl; */

     for (int i = 0; i < out.size(); i++)
    {
        //cout << "/////" << endl;
        //for (int j = 0; j < out[i].size(); j++)
        {
            cout << out[i]<< "--" << out[i].size() << endl; 
        }
    }
    //cout << endl;
    
    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;

    return 0;
}
/* ["Science   is what we","understand      well","enough to explain to","a   computer. Art is","everything  else  we","do                  "]
   ["Science  is  what we","understand      well","enough to explain to","a  computer.  Art is","everything  else  we","do                  "] */