#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        rw = matrix.size();
        cl = rw ?  matrix[0].size() : 0;
        sumMatrix = vector<vector<int>>(rw + 1, vector<int> (cl + 1, 0));
        for (int i = 1; i < rw + 1; ++i){
            for (int j = 1; j < cl + 1; ++j){
                sumMatrix[i][j] = matrix[i - 1][j - 1] + 
                sumMatrix[i - 1][j] + sumMatrix[i][j - 1] - sumMatrix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {        
        return sumMatrix[row2 + 1][col2 + 1] - sumMatrix[row1][col2 + 1] - sumMatrix[row2 + 1][col1] + sumMatrix[row1][col1];
    }
private:
    int rw, cl;
    vector<vector<int>> sumMatrix;
};
