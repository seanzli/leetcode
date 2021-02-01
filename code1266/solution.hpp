#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int sum = 0;
        for (int i = 0; i < points.size()-1; i++)
            sum += distance(points[i],points[i+1]);
        return sum;        
    }
    int distance(vector<int> point1, vector<int> point2){
        int dif_x = abs(point2[0] - point1[0]);
        int dif_y = abs(point2[1] - point1[1]);

        return (min(dif_x+dif_y, min(dif_x,dif_y)+abs(dif_y-dif_x)));
    }
};