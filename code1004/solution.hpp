#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int left = 0, count = 0;
        int max_length = 0;
        for (int right = 0; right < n; right++) {
            if (A[right] == 0)
                count++;
            while (count > K) {
                if (A[left] == 0)
                    count--;
                left++;
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};