#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/* class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = INT_MIN, count=1;
        vector<int>::iterator itr = nums.begin();

        while (itr!=nums.end())
        {
            if (cur == *itr)
            {
                if (count==2)
                {
                    itr = nums.erase(itr);
                    continue;
                }    
                else                
                    count++;
            }
            else{
                count=1;
                cur = *itr;
            }
            ++itr;
        }

        return nums.size();
    }
}; */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return n;
        int left = 2;
        for (int right = 2; right < n; right++) {
            if (nums[left - 2] == nums[right]) {
                cout << right << endl;
                continue;
            }
            else
                nums[left++] = nums[right];
        }
        return left;
    }
};