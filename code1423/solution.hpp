#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> m_vec;
        int n = cardPoints.size();
        int cur_sum = 0, max_sum = 0;
        for (int i = n - k; i < n; i++){
            m_vec.push_back(cardPoints[i]);
            cur_sum += cardPoints[i];
        }
        max_sum = cur_sum;
        for (int i = 0; i<k; i++)
            m_vec.push_back(cardPoints[i]);
        
        for (int i = 0; i+k<m_vec.size(); i++){
            cur_sum -= m_vec[i];
            cur_sum += m_vec[i+k];
            max_sum = max(cur_sum, max_sum);
        }
        return max_sum;
    }
};