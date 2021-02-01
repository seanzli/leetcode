#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <regex>
#include <string>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) 
    {
        return b ? gcd(b, a % b) : a;
    }
    string fractionAddition(string expression) {
        int n = 0;
        for (auto c: expression)
            if (c == '/')
                n ++ ;
        expression = '+' + expression;
        int a = 0, b = 1, offset = 0;
        int c, d;
        char e;
        for (int i = 0; i < n; i ++ ) {
            sscanf(expression.c_str() + offset, "%c%d/%d", &e, &c, &d);
            offset += (e + to_string(c) + '/' + to_string(d)).size();
            if (e == '-') c = -c;
            int x = a * d + b * c, y = b * d;
            int z = abs(gcd(x, y)); // 最大公约数
            a = x / z, b = y / z;
        }

        return to_string(a) + '/' + to_string(b);
    }
};