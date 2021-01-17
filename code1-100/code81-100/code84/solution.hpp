#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>


using namespace std;

class Solution {
public:
/*     int largestRectangleArea(vector<int>& heights) {
        stack<int> idx;
        int cur_height_idx;
        int max_value = INT_MIN;
        int n = heights.size();

        for (int i = 0; i < heights.size(); i++)
        {
            if ((idx.empty()) || (heights[i] > heights[idx.top()]))
                idx.push(i);
            else
            {
                while ((!idx.empty()) && (heights[i] <= heights[idx.top()]))
                {
                    cur_height_idx = idx.top(); idx.pop();
                    if (idx.empty())
                        max_value = max(max_value, heights[cur_height_idx]*(i));
                    else
                        max_value = max(max_value, heights[cur_height_idx]*(i-idx.top()-1));
                }
                idx.push(i);
            }
        }
        while (!idx.empty())
        {
            cur_height_idx = idx.top(); idx.pop();
            if (idx.empty())
                max_value = max(max_value, heights[cur_height_idx]*n);
            else
                max_value = max(max_value, heights[cur_height_idx]*(n-idx.top()-1));
        }
        return max_value;
    } */

    int largestRectangleArea(vector<int>& heights) {
        int maxarea=0;
        for(int i=0;i<heights.size();++i){
            if(i>0 && heights[i]==heights[i-1]) continue;
            int l=i,r=i;
            while(l>0 && heights[l-1]>=heights[i])    --l;
            while(r+1<heights.size() && heights[r+1]>=heights[i])    ++r;
            maxarea=max(maxarea,(r-l+1)*heights[i]);
        }
        return maxarea;
    }
};