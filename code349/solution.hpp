#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> m_set;
        vector<int> out;
        for (int i : nums1)
            m_set.insert(i);
        for (int i : nums2){
            if (m_set.count(i)){
                out.push_back(i);
                m_set.erase(i);
            }
        }
        return out;
    }
};