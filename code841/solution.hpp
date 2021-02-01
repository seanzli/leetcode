#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> un_lockroom(rooms.size(), 0);
        queue<int> m_queue;
        for (int i:rooms[0]){
            m_queue.push(i);
        }
        un_lockroom[0]=1;
        while (m_queue.size()){
            int n = m_queue.size();
            for (int i = 0; i < n; i++)
            {
                int cur = m_queue.front(); m_queue.pop();
                if (un_lockroom[cur] == 0){
                    un_lockroom[cur] = 1;
                    for (int j = 0; j < rooms[cur].size(); j++)
                    {
                        if (un_lockroom[rooms[cur][j]]==0)
                            m_queue.push(rooms[cur][j]);
                    }
                }
            }
        }
        
        for (int i : un_lockroom){
            if (i == 0)
                return false;
        }
        return true;
    }
};