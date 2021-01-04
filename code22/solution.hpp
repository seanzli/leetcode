#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    char int2char(int i)
    {
        if (i==0)
            return '(';
        else
            return ')';
    }
    int byte2int(int i)
    {
        if (i==0)
            return -1;
        else
            return 1;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        char *cur=new char[n*2+1]();
        int sum, mark=0;
        for (int i = 0; i<(1<<(n*2)); i++)
        {
            for (int j = 0; j < n*2; j++)
            {
                sum += byte2int(i&(1 << j));
                if (sum < 0)
                    break;
                cur[n*2-1-j] = int2char(i&(1 << j));
            }
            if (sum==0)
                out.push_back(string(cur));
            sum = 0;
        }
        return out;
    }
};