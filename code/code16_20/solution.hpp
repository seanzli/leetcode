#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    char char2int(char a){
        if (a <='c')
            return '2';
        else if (a <= 'f')
            return '3';
        else if (a <= 'i')
            return '4';
        else if (a <= 'l')
            return '5';
        else if (a <= 'o')
            return '6';
        else if (a <= 's')
            return '7';
        else if (a <= 'v')
            return '8';
        else
            return '9';
    }
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> out;
        for (string i : words)
        {
            string cmp;
            for (int cur : i)
                cmp = cmp + char2int(cur);
            if (cmp.compare(num)==0)
                out.push_back(i);
        }
        return out;
    }
};