#include <vector>
#include <string>

using namespace std;

class Solution {
    int row, col;
    vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        visited = vector<vector<bool>>(row, vector<bool>(col, false));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int idx) {
        if (idx == word.size())
            return true;

        if (i >= 0 && i < row && j >= 0 && j < col && visited[i][j] == false && board[i][j] == word[idx]) {
            visited[i][j] = true;
            if (dfs(board, i + 1, j, word, idx + 1))
                return true;
            if (dfs(board, i - 1, j, word, idx + 1))
                return true;
            if (dfs(board, i, j + 1, word, idx + 1))
                return true;
            if (dfs(board, i, j - 1, word, idx + 1))
                return true;
            visited[i][j] = false;
        }
        return false;
    }
};