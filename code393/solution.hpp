#include <cstdio>
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0;
        while (i < data.size()) {
            int idx = firstZero(data[i]);
            if (idx == 0) {
                i++;
                continue;
            }
            if (idx == 1 || idx == string::npos || idx > 4)
                return false;
            while (idx > 1) {
                i++;
                if (i == data.size() || firstZero(data[i]) != 1)
                    return false;
                idx--;
            }
            i++;
        }
        return true;
    }

    int firstZero(int n) {
        bitset<8> m(n);
        string str = m.to_string();
        return str.find_first_of('0');
    }
};