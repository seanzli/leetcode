#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> out(n, vector<int>(n));
        
        int l_left=0, l_rigth=n, l_up=1, l_bottom=n;
        int i=0,j=0;
        int vec = 0;//0=right 1=dowm 2=left 3=up
        for (int cur = 1; cur<=n*n; cur++)
        {
            out[i][j]=cur;
            switch (vec)
            {
            case 0: //right
            {
                j++;
                if (j==(l_rigth-1))
                {
                    vec = (++vec)%4;
                    l_rigth--;
                }
                break;
            }
            case 1: //down
            {
                i++;
                if (i==(l_bottom-1))
                {
                    vec = (++vec)%4;
                    l_bottom--;
                }
                break;
            }
            case 2: //left
            {
                j--;
                if (j==l_left)
                {
                    vec = (++vec)%4;
                    l_left++;
                }
                break;
            }
            case 3: //up
            {
                i--;
                if (i==l_up)
                {
                    vec = (++vec)%4;
                    l_up++;
                }
                break;
            }
            default:
                break;
            }
        }
        return out;
    }
};