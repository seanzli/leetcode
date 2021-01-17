#include <vector>
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    int numberLeft(vector<vector<char>>& board,int i, int j, vector<char> &out)
    {
        out.clear();
        int taken[10] = {0};
        for (int idx = 0; idx < 9; idx++)
        {
            if (board[i][idx]!='.')
                taken[board[i][idx]-'0']=1;
            if (board[idx][j]!='.')
                taken[board[idx][j]-'0']=1;
        }
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (board[row+i/3*3][col+j/3*3]!='.')
                taken[board[row+i/3*3][col+j/3*3]-'0']=1;
            }
        }
        for (int idx = 1; idx < 10; idx++)
        {
            if (taken[idx] == 0)
                out.push_back(idx+'0');
        }
        return out.size();
    }
    bool getNnknowPosition(vector<vector<char>> &board, int& i, int& j){
        for ( i = 0; i < 9; i++)
        {
            for ( j = 0; j < 9; j++)
            {
                if (board[i][j]=='.')
                {
                    return true;
                }
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> orj = board;
        vector<char> back_num[81];
        stack<pair<int,int>> gauss_list;
        pair<int,int> cur;
        int i,j;
        while(getNnknowPosition(board,i,j)){ //all know then solved
            if(numberLeft(board,i,j,back_num[i*9+j])){ // find backup num
                board[i][j] = back_num[i*9+j][back_num[i*9+j].size()-1];
                gauss_list.push(pair<int,int>(i,j));
                back_num[i*9+j].pop_back();
            }
            else{
                while (1)
                {
                    board[i][j] = '.';
                    if (gauss_list.empty())
                        return;
                    cur = gauss_list.top();
                    i = cur.first; j=cur.second;
                    if (back_num[i*9+j].size()>0)
                    {
                        board[i][j] = back_num[i*9+j][back_num[i*9+j].size()-1];
                        back_num[i*9+j].pop_back();
                        break;
                    }
                    else
                    {
                        gauss_list.pop();
                    }
                    
                }
            }
        }
    }
};