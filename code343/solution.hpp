#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        long result = 1;
        while(n > 4){
            n -= 3;
            result *= 3;
        }
        return (int)(n * result);
    }
};