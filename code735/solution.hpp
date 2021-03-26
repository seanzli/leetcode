#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

/* class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> out;
        for (int cur : asteroids) {
            if (cur > 0) {
                out.push_back(cur);
            } else {
                while (out.size()) {
                    if (out.back() < 0)
                        break;
                    if (abs(cur) == out.back()) {
                        cur = 0;
                        out.pop_back();
                        break;
                    } else if (abs(cur) > out.back()) {
                        out.pop_back();
                    } else {
                        cur = 0;
                        break;
                    }
                }
                if (cur != 0)
                    out.push_back(cur);
            }
        }
        return out;
    }
}; */

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (int i = 0; i < asteroids.size(); i++) {
            bool flag = true;
            while (res.size() > 0 && res.back() > 0 && asteroids[i] < 0) {
                if (-asteroids[i] > res.back()) {
                    res.pop_back();
                } else if (-asteroids[i] == res.back()) {
                    res.pop_back();
                    flag = false;
                    break;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag)
                res.push_back(asteroids[i]);
        }
        return res;
    }
};