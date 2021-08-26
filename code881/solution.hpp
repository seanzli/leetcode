/*
 * @Description: 
 * @Author: Sean
 * @Date: 2021-08-26 20:21:17
 * @LastEditTime: 2021-08-26 20:38:37
 * @LastEditors: Sean
 * @Reference: 
 */

#include <vector>
// #include <queue>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0;
        int left = 0, right = people.size() - 1;
        while (left <= right) {
            if (people[left] + people[right] > limit) {
                right--;
            } else {
                left++;
                right--;
            }
            res++;
        }
        return res;
    }
};