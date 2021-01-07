#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <math.h>

using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> out;
        string cur_string;
        // new line
        for (int i = 0; i < n; i++)
            cur_string += ".";
        
        vector<string> cur_map(n, cur_string);

        dsp(cur_map, out, 0, n);
        return out;
    }
    void dsp(vector<string> &cur_map, vector<vector<string>> &out, int i, int n){
        if (i == n)
        {
            out.push_back(cur_map);
            return;
        }
        
        for (int j = 0; j < n; j++)
        {
            if (isValid(cur_map, i, j))
            {
                cur_map[i][j]='Q';
                dsp(cur_map, out, i+1, n);
            }
            cur_map[i][j]='.';
        }
        return;
    }
    
    bool isValid(vector<string> &temp, int i, int j){
        for (int k = 0; k < i; ++k){//判断列
            if (temp[k][j] == 'Q') return false;
        }
        for (int p = i - 1, q = j - 1; p>=0 && q>=0; --p, --q){//判断左上对角线
            if (temp[p][q] == 'Q') return false;
        }
        for (int p = i - 1, q = j + 1; p >= 0 && q<temp.size(); --p, ++q){//判断右上对角线
            if (temp[p][q] == 'Q') return false;
        }
        return true;
    }
};