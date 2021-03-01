#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

/* class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        deque<int> m_que;
        for (int i : arr)
            m_que.push_back(i);
        int win = -1, win_count = 0;
        while (win_count < k) {
            int first = m_que.front(); m_que.pop_front();
            int second = m_que.front(); m_que.pop_front();
            if (first > second) {
                win = first;
                win_count++;
                m_que.push_back(second);
                m_que.push_front(first);
            } else {
                win = second;
                win_count = 1;
                m_que.push_back(first);
                m_que.push_front(second);
            }
        }
        return win;
    }
}; */

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int win = max(arr[0], arr[1]);
        int win_count = 1;
        if (k == 1)
            return win;
        for (int i = 2; i < n; i++) {
            if (arr[i] > win) {
                win = arr[i];
                win_count = 1;
            } else {
                win_count++;
                if (win_count == k)
                    return win;
            }
        }
        return win;
    }
};