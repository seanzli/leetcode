#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution {
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
};