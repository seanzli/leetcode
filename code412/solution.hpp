#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 1; i <= n; i++) {
            string str = "";
            if (i % 3 == 0)
                str += "Fizz";
            if (i % 5 == 0)
                str += "Buzz";
            if (str.size() == 0)
                str = to_string(i);
            res[i - 1] = str;
        }
        return res;
    }
};