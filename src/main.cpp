
#include "../code36/solution.hpp"
#include <ctime>

int main(int argc, char* argv[])
{
    clock_t start_time, end_time;
    start_time = clock();
    Solution *test = new Solution();

    string s = "()(()";

    vector<vector<char>> board;
    board.push_back({'8','3','.','.','7','.','.','.','.'});
    board.push_back({'6','.','.','1','9','5','.','.','.'});
    board.push_back({'.','9','8','.','.','.','.','6','.'});
    board.push_back({'8','.','.','.','6','.','.','.','3'});
    board.push_back({'4','.','.','8','.','3','.','.','1'});
    board.push_back({'7','.','.','.','2','.','.','.','6'});
    board.push_back({'.','6','.','.','.','.','2','8','.'});
    board.push_back({'.','.','.','4','1','9','.','.','5'});
    board.push_back({'.','.','.','.','8','.','.','7','9'});

    cout << test->isValidSudoku(board) << endl;
    cout << (double)(clock() - start_time)/CLOCKS_PER_SEC << endl;
    return 0;
}