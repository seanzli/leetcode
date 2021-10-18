#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        std::bitset<32> s(num);
        std::string str = s.to_string();

        int idx = 0;
        for (idx = 0; idx < str.size(); ++idx) {
            if (str[idx] == '1')
                break;
        }

        for (idx; idx < str.size(); ++idx) {
            if (str[idx] == '0')
                str[idx] = '1';
            else
                str[idx] = '0';
        }

        std::bitset<32> s2(str);

        return s2.to_ulong();
    }
};