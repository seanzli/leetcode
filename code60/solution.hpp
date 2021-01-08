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
/*     string getPermutation(int n, int k) {
        vector<char> cur;
        for (int i = 1; i <= n; i++)
            cur.push_back('0'+i);

        for (int i = 1; i < k; i++)
        {
            next_permutation(cur.begin(), cur.end());
        }
        string s = string((const char*)(&*cur.begin()), n);
        return s;
    } */
    string getPermutation(int n, int k) {
        vector<int> n_factorial;
        vector<int> idx, flag(n+1);
        int factorial = 1, count=0;
        n_factorial.push_back(1);
        for (int i = 1; i < n; i++)
        {
            factorial = factorial*i;
            n_factorial.push_back(factorial);
        }
        int i,j;
        for (i = n-1; i >=0; i--)
        {
            for (j = 1; j <= n; j++)
            {
                if (count + n_factorial[i] >=k)
                    break;
                count = count + n_factorial[i];
            }
            idx.push_back(j);
        }
        string out;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (flag[j]==0)
                    count++;
                if (count == idx[i])
                {
                    out += ('1'+j);
                    flag[j] = 1;
                    break;
                }

            }
        }
        return out;    
    }
};