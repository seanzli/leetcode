#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int row, col;
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> board_orj = board;
        row = board.size();
        col = board[0].size();
        int count = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                count = getLiveNum(board, i, j);
                if (board[i][j]== 1){
                    if (count < 2)
                        board_orj[i][j] = 0;
                    else if (count < 4)
                        board_orj[i][j] = 1;
                    else
                        board_orj[i][j] = 0;
                }else{
                    if (count == 3)
                        board_orj[i][j] = 1;
                }
            }
        }
        board = board_orj;
    }
    int getLiveNum(vector<vector<int>>&board, int i_row, int i_col){
        int count = 0;
        for (int i = i_row-1; i <= i_row+1; i++)
        {
            for (int j = i_col-1; j <= i_col+1; j++)
            {
                if ((i == i_row) && (j == i_col))
                    continue;
                if (i>=0 && i<row && j>=0 && j<col && board[i][j]== 1)
                    count++;
            }
            
        }
        return count;
    }
};