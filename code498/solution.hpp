#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> out;
    int row, col;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        row = matrix.size();
        if (row == 0)
            return out;
        col = matrix[0].size();
        for (int i = 0;i <= (row+col);i++)
            genIdx(matrix, i);
        return out;
    }
    void genIdx(vector<vector<int>> & matrix, int idx){
        int x, y;
        if (idx%2==1){ // up
            for (int i = 0; i <= idx; i++)
            {
                x = i;y = idx-i;
                if (x<row && y<col)
                    out.push_back(matrix[x][y]);
            }
        } else {
            for (int i = 0; i <= idx; i++)
            {
                x = idx - i;y = i;
                if (x<row && y<col)
                    out.push_back(matrix[x][y]);
            }
        }
    }
};