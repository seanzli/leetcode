#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <math.h>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
private:
    int row, col;

public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int count = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j]=='1'){
                    gen(grid, i,j);
                    count++;
                }
            }
        }
        return count;
    }
    void gen(vector<vector<char>>& grid, int i, int j){
        if ((i>=0) && (i<row) && (j>=0) && (j<col) && grid[i][j]=='1'){
            grid[i][j] = '2';
            gen(grid, i+1, j);
            gen(grid, i-1, j);
            gen(grid, i, j-1);
            gen(grid, i, j+1);
        }
        return;
    }
};