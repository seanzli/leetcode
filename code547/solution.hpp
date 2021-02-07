#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    int n;
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        int count = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (isConnected[i][j]==1){
                    count++;
                    int row = i, col = j;
                    isConnected[i][j] = 0;
                    clearConnect(isConnected, row, col);
                }
            }
        }
        return count;
    }

    void clearConnect(vector<vector<int>> &isConnected, int row, int col){
        for (int i = 0; i < n; i++)
        {
            if (isConnected[i][row] == 1){
                isConnected[i][row] = 0;
                clearConnect(isConnected, i, row);
            }
            if (isConnected[row][i] == 1){
                isConnected[row][i] = 0;
                clearConnect(isConnected, row, i);
            }
        }
        return;
    }
};