#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int n_2 = 0;
		int n_1 = 0;
		int ret_n = 1;
		for (int i = 1;i<=n;i++)
		{
			n_2 = n_1;
			n_1 = ret_n;
			ret_n = n_2 + n_1;
		}
		return ret_n;
    }
};