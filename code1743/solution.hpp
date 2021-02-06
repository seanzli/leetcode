#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> hash; // key -> map
        for (auto i : adjacentPairs){
            hash[i[0]].push_back(i[1]);
            hash[i[1]].push_back(i[0]);
        }
        
        vector<int> out;
        for (auto itr = hash.begin(); itr!= hash.end(); itr++){
            if (itr->second.size()==1){
                out.push_back(itr->first);
                break;
            }
        }
        while (hash.size()){
            int key = out.back();
            int val = hash[key].back();
            out.push_back(val);
            hash[key].pop_back();
            if (hash[key].size()==0)
                hash.erase(key);
            auto itr = find(hash[val].begin(), hash[val].end(), key);
            if (itr!=hash[val].end())
                hash[val].erase(itr);
            if (hash[val].size()==0)
                hash.erase(val);
        }
        return out;
    }
};