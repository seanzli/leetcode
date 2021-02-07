#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<int> out;
        vector<int> out2;
        out.push_back(0);
        for (int i = 1; i<favoriteCompanies.size(); i++){
            int j = 0;
            for (; j<out.size(); j++){
                if (isContain(favoriteCompanies[i], favoriteCompanies[out[j]]))
                    break;
                if (isContain(favoriteCompanies[out[j]], favoriteCompanies[i])){
                    out[j] = i;
                }
            }
            if (j == out.size())
                out.push_back(i);
        }
        sort(out.begin(), out.end());
        for (int i: out){
            if (out2.size() && i==out2.back())
                continue;
            out2.push_back(i);
        }
        return out2;
    }
    bool isContain(vector<string> a, vector<string> b){ //b contain a
        for (string i : a){
            auto itr = find(b.begin(), b.end(), i);
            if (itr == b.end())
                return false;
        }
        return true;
    }
};

#include <map>
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        for (auto& f : favoriteCompanies) {
            sort(f.begin(), f.end());
        }

        map<int, vector<int>> mapSizeIndex;
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            mapSizeIndex[favoriteCompanies[i].size()].push_back(i);
        }

        vector<int> ans;
        for (auto it = mapSizeIndex.rbegin(); it != mapSizeIndex.rend(); it++) {
            for (auto& p : it->second) {
                if (it != mapSizeIndex.rbegin() && checkIncludes(favoriteCompanies, ans, p)) continue;
                ans.push_back(p);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }

    bool checkIncludes(vector<vector<string>>& fc, vector<int>& ans, int p) {
        for (auto i : ans) {
            if (includes(fc[i].begin(), fc[i].end(), fc[p].begin(), fc[p].end())) return true;
        }
        return false;
    } 
};
