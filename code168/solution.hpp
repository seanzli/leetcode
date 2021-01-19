#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class Solution {
public:
    char int2char(int i){
        return ('A' + i);
    }
    string convertToTitle(int n) {
        string out;
        while(n>0){
            n = n -1;
            out = out + int2char(n%26);
            n = n/26;
        }
        reverse(out.begin(), out.end());
        return out;
    }
};

//code169
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num : nums) {
            if (num == candidate)
                ++count;
            else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};