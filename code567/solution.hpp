#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1>n2)  return false;
        
        unordered_map<char, int> hash_s1, hash_s2;
        for (char cur : s1)
            hash_s1[cur]++;
        for (int i = 0; i < n1; i++)
            hash_s2[s2[i]]++;
        if (hash_s1 == hash_s2)
            return true;
        int left = 0, right = n1;
        while (right < n2){
            hash_s2[s2[left]]--;
            hash_s2[s2[right]]++;
            if (hash_s2[s2[left]] ==0)
                hash_s2.erase(s2[left]);
            if (hash_s1 == hash_s2)
                return true;
            left++;
            right++;
        }
        return false;        
    }
};