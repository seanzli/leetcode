#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        vector<int> res; // idx
        int out = 0;
        for (int i = 0; i < s.size(); i++) {
            if (res.size() && s[res.back()] == s[i]) {
                if (cost[res.back()] < cost[i]) {
                    out += cost[res.back()];
                    res[res.size() - 1] = i;
                }
                else
                    out += cost[i];
            } else {
                res.push_back(i);
            }
        }
        return out;
    }
};

/* class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int len = s.length();
        int sum = 0;
        for(int i = 0; i < len - 1; i++)
        {
            if(s[i] == s[i+1])
            {
                if(cost[i] > cost[i+1])
                {
                    int temp = cost[i];
                    cost[i] = cost[i+1];
                    cost[i+1] = temp;
                }
                sum += cost[i];
            }
        }
        return sum;
    }
}; */