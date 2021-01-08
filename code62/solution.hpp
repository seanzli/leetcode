#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <math.h>
#include <list>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        m = m -1;
        n = n - 1;
/*         if (m*n==0)
            return 1; */
        
        int out = 1, up = min(m,n), down = m+n;
        double div1 = 1, div2 = 1;
        for (int i = 0; i < up; i++)
        {
            div1 = div1*(up-i);
            div2 = div2*(down-i);
        }
        
        return (div2/div1);
    }
};