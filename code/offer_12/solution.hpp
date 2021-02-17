#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int row, col;
    vector<vector<bool>> picked;
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        picked = vector<vector<bool>>(row, vector<bool>(col, false));
        vector<pair<int, int>> backup;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (word[0] == board[i][j]){
                    picked[i][j] = true;
                    if (dfs(i, j, board, word, 1))
                        return true;
                    picked[i][j] = false;
                }
            }
        }
        return false;
    }

private:
    bool dfs(int i, int j, vector<vector<char>>& board, string word, int idx){
        if (idx == word.size())
            return true;
        if (i+1 < row && picked[i+1][j] == false && board[i+1][j] == word[idx]){
            picked[i+1][j] = true;
            if (dfs(i+1, j, board, word, idx+1))
                return true;
            picked[i+1][j] = false;
        }
        if (i-1 >= 0 && picked[i-1][j] == false && board[i-1][j] == word[idx]){
            picked[i-1][j] = true;
            if (dfs(i-1, j, board, word, idx+1))
                return true;
            picked[i-1][j] = false;
        }
        if (j+1 < col && picked[i][j+1] == false && board[i][j+1] == word[idx]){
            picked[i][j+1] = true;
            if (dfs(i, j+1, board, word, idx+1))
                return true;
            picked[i][j+1] = false;
        }
        if (j-1 >= 0 && picked[i][j-1] == false && board[i][j-1] == word[idx]){
            picked[i][j-1] = true;
            if (dfs(i, j-1, board, word, idx+1))
                return true;
            picked[i][j-1] = false;
        }
        return false;
    }
};