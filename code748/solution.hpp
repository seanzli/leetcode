#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, int> hash;
    vector<char> vec;
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        char cur;
        for (int i = 0; i< licensePlate.size(); i++)
        {
            if ((licensePlate[i]>='a') && (licensePlate[i]<='z')){
                hash[licensePlate[i]]++;
                if (hash[licensePlate[i]] == 1)
                    vec.push_back(licensePlate[i]);
            }
            if ((licensePlate[i]>='A') && (licensePlate[i]<='Z')){
                hash[licensePlate[i]-'A'+'a']++;
                if (hash[licensePlate[i]-'A'+'a'] == 1)
                    vec.push_back(licensePlate[i]-'A'+'a');
            }
        }

        int short_length = INT_MAX;
        int short_idx = 0;

        for (int i = 0; i< words.size(); i++)
        {
            if (words[i].size() < vec.size())
                continue;
            if (countChar(words[i])){
                if (words[i].size() < short_length){
                    short_idx = i;
                    short_length = words[i].size();
                }
            }
        }
        return words[short_idx];
    }

    bool countChar(string s){
        char cur;
        int num;
        for (int i = 0; i<vec.size(); i++){
            cur = vec[i];
            num = hash[cur];
            string cur_s = s;
            for (int j = 0; j < num; j++)
            {
                if (cur_s.find(cur) == cur_s.npos)
                    return false;
                cur_s = cur_s.substr(cur_s.find(cur)+1);
            }
        }
        return true;
    }
};