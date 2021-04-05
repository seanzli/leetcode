#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <math.h>
#include <queue>
#include <limits.h>
#include <unordered_set>
#include <set>

using namespace std;

/* class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
}; */
class Solution {
    set<int> hash; // check is primes
public:
    int countPrimes(int n) {
        if (n <= 1)
            return 0;
        
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime(i))
                res++;
        }
        return res;
    }
    bool isPrime(const int& x) {
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
            int cur = *itr;
            if (cur * cur > x)
                break;
            if (x % cur == 0)
                return false;
        }
        hash.insert(x);
        return true;
    }
};