#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/* class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int length_s = s.size(), length_p = p.size();
        int left = 0, right;
        unordered_map<int, int> hash_cur, hash_p;
        for (right = 0; right < length_p; right++) {
            hash_cur[s[right]]++;
            hash_p[p[right]]++;
        }
        if (hash_cur == hash_p)
            res.push_back(0);

        for ( ;right < length_s; right++) {
            hash_cur[s[right]]++;
            hash_cur[s[left]]--;
            if (hash_cur[s[left]] == 0)
                hash_cur.erase(s[left]);
            left++;
            if (hash_p == hash_cur)
                res.push_back(left);
        }
        return res;
    }
}; */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vec(26, 0);
        vector<int> vec_zero(26, 0);
        vector<int> res;
        if (s.size() < p.size())
            return res;
        for (int i = 0; i < p.size(); i++) {
            vec[s[i] - 'a']++;
            vec[p[i] - 'a']--;
        }

        if (vec == vec_zero) {
            res.push_back(0);
        }

        for (int i = p.size(); i < s.size(); i++) {
            vec[s[i] - 'a']++;
            vec[s[i - p.size()] - 'a']--;
            if (vec == vec_zero)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};