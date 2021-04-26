#include <map>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

/* class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> hash; // value -> index
        for (int i = 0; i < arr.size(); i++) {
            if (hash.find(arr[i]) == hash.end()) {
                hash[arr[i]] = {i};
            } else {
                hash[arr[i]].push_back(i);
            }
        }
        int i = 0;
        for (auto itr : hash) {
            i++;
            for (int idx : itr.second) {
                arr[idx] = i;
            }
        }
        return arr;
    }
}; */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> tmp(arr.begin(), arr.end());
        sort(tmp.begin(), tmp.end());
        int end = unique(tmp.begin(), tmp.end()) - tmp.begin();

        vector<int> res(arr.size());

        for (int idx=0; idx<arr.size(); ++idx){
            res[idx] = lower_bound(tmp.begin(), tmp.begin() + end, arr[idx]) - tmp.begin() + 1;
        }

        return res;
    }
};