#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return { 0 };
        else if (n == 2)
            return{ 0,1 };

        vector<int> indegree(n,0);//入度数组，并初始化
        vector<int> v;
        vector<vector<int>> graph(n,v);//图形表示，并初始化
        for (int i = 0; i < edges.size(); i++)//构造图与入度数组：无向图，两个点都要处理
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        queue<int> myqueue;//装载入度为1的queue
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
                myqueue.push(i);
        }
        int cnt = myqueue.size();//！！令cnt等于myqueue.size()，一次性将入度为1的点全部删去。
        while (n>2)
        {
            n -= cnt;//一次性将入度为一的点全部删去！！不能一个一个删！
            while (cnt--)
            {
                int temp = myqueue.front();
                myqueue.pop();
                indegree[temp] = 0;
                //更新temp的邻接点：若temp临接点的入度为1，则将其放入queue中。
                for (int i = 0; i < graph[temp].size(); i++)
                {
                    if (indegree[graph[temp][i]] != 0)
                    {
                        indegree[graph[temp][i]]--;
                        if (indegree[graph[temp][i]] == 1)//放在这里做！只判断邻接点。
                            myqueue.push(graph[temp][i]);
                    }
                    
                }
            }
            cnt = myqueue.size();
        }
        vector<int> result;
        while (!myqueue.empty())
        {
            result.push_back(myqueue.front());
            myqueue.pop();
        }
        return result;
    }
};