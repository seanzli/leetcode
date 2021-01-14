#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> pre;// = triangle[0];
        vector<int> cur = triangle[0];
        for (int i = 1; i < triangle.size(); i++)
        {
            pre = cur;
            cur.clear();
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (j==0) 
                    cur.push_back(triangle[i][0] + pre[0]);
                else if (i==j)
                    cur.push_back(triangle[i][j]+pre.back());
                else
                    cur.push_back(min(triangle[i][j] + pre[j], 
                                      triangle[i][j] + pre[j-1]));
            }
        }
        return *min_element(cur.begin(), cur.end());
    }
};