#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>res;
        for(int i=0;i+9<s.size();i++){
            auto key=s.substr(i,10);
            if(mp[key]==1)res.push_back(key);
                mp[key]++;
        }
        return res;
    }
};