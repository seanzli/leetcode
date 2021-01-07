#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), cur;
        for (int i = 0; i < n/2; i++)
        {
            for (int j = i; j < n-i-1; j++)
            {
                cur = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = cur;
                
                cout << "i = " << i<<",j="<<j <<endl; 
                for (int i = 0; i < matrix.size(); i++)
                {
                    for (int j = 0; j < matrix[i].size(); j++)
                    {
                        cout << matrix[i][j] << ",";
                    }
                    cout << endl;
                }
            }

        }
    }
};