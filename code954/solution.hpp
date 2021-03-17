#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> hash_pos; // num , count
        map<int, int, ::greater<int>> hash_neg; // num , count
        int zero_count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0)
                zero_count++;
            else if (arr[i] > 0)
                hash_pos[arr[i]]++;
            else
                hash_neg[arr[i]]++;
        }
        if (zero_count % 2 == 1)
            return false;
        
        while (hash_pos.size()) {
            auto itr = hash_pos.begin();
            int small = itr->first;
            int small_count = itr->second;
            if (hash_pos[2*small] < small_count)
                return false;
            hash_pos[2*small] -= small_count;
            hash_pos.erase(small);
            if (hash_pos[2*small] == 0)
                hash_pos.erase(2*small);
        }
        
        while (hash_neg.size()) {
            auto itr = hash_neg.begin();
            int small = itr->first;
            int small_count = itr->second;
            if (hash_neg[2*small] < small_count)
                return false;
            hash_neg[2*small] -= small_count;
            hash_neg.erase(small);
            if (hash_neg[2*small] == 0)
                hash_neg.erase(2*small);
        }
        return true;
    }
};