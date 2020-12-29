/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example: */

/* 
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]. 
*/

#include <iostream>

class Solution
{
public:
    Solution(){};
    ~Solution(){};

    void mainFunction(){
        using namespace std;

        int num[4] = {2,7,11,15};
        int target = 9;

        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = i+1; j < 4; j++)
            {
                if (num[i]+num[j] == target)
                {
                    cout << i << j << endl;
                    return;
                }   
            }   
        }
        cout << "none" << endl;
    }
};