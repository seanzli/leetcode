#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> rows, cols;
    int row, col;
    void solve(vector<vector<char>>& board) {
        row = board.size();
        if (row<1)
            return;
        col = board[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j]=='O')
                {
                    getNeighbor(board, i,j);
                    if ((*max_element(rows.begin(), rows.end()) < row-1) &&
                        (*max_element(cols.begin(), cols.end()) < col-1) &&
                        (*min_element(rows.begin(), rows.end()) > 0) && 
                        (*min_element(cols.begin(), cols.end()) > 0))
                        ;
                    else
                    {
                        for (int iRow = 0; iRow < rows.size(); iRow++)
                            board[rows[iRow]][cols[iRow]] = 'O';
                    }
                    rows.clear(), cols.clear();
                }
            }
        }
    }
    void getNeighbor(vector<vector<char>>&board, int i, int j){
        if ((i<0) || (i>=row) || (j<0) || (j>=col)) return;
        if (board[i][j]=='O')
        {
            rows.push_back(i);cols.push_back(j);
            board[i][j] = 'X';
            getNeighbor(board, i+1, j);
            getNeighbor(board, i-1, j);
            getNeighbor(board, i, j+1);
            getNeighbor(board, i, j-1);
        }
    }
};