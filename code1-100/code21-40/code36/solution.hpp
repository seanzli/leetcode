#include <vector>
#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
public:
/*     bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> hash_row;
        unordered_map<char, int> hash_col;
        // row col check
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9;j++)
            {
                if (board[i][j] != '.')
                {
                    if (hash_row.find(board[i][j]) == hash_row.end())
                        hash_row[board[i][j]] = 1;
                    else
                        return false;
                }
                
                if (board[j][i] != '.')
                {
                    if (hash_col.find(board[j][i]) == hash_col.end())
                        hash_col[board[j][i]] = 1;
                    else
                        return false;
                }
            }
            hash_row.clear();
            hash_col.clear();
        }

        // mid check
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int m = 0; m < 3; m++)
                {
                    for (int n = 0; n < 3; n++)
                    {
                        if (board[i*3+m][j*3+n]!='.')
                        {
                            hash_row[board[i*3+m][j*3+n]]++;
                            if (hash_row[board[i*3+m][j*3+n]]>1) 
                                return false;
                        }
                    }
                }
                hash_row.clear();
            }
        }
        return true;
    } */
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10]={0};
        int col[9][10] = {0};
        int box[9][10] = {0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                int curnum = board[i][j] - '0';
                if(row[i][curnum])  return false;
                if(col[j][curnum])  return false;
                if(box[i/3*3+j/3][curnum])    return false;
                row[i][curnum] =1;
                col[j][curnum]=1;
                box[i/3*3+j/3][curnum]=1;
            }
        }
        return true;
    }
};