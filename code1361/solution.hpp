#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> in(n, 0);
        int root = -1;

        // indegree outdegree calc
        for (int i=0; i<n; i++){
            if (leftChild[i] >=0){
                in[leftChild[i]]++;
            }
            if (rightChild[i] >=0){
                in[rightChild[i]]++;
            }
        }

        // find root -> indegree == 0
        for (int i=0; i<n; i++){
            if (in[i] == 0){
                if (root >=0)
                    return false;
                root = i;
            }
        }
        if (root < 0) //no root;
            return false;

        //bfs
        queue<int> m_que;
        vector<bool> checked(n, false);
        m_que.push(root);
        while (m_que.size()>0){
            int n = m_que.size();
            for (int i=0; i<n; i++){
                int cur = m_que.front(); m_que.pop();
                if (checked[cur] == true)
                    return false;
                checked[cur] = true;
                
                if (leftChild[cur] >=0)
                    m_que.push(leftChild[cur]);
                if (rightChild[cur] >=0)
                    m_que.push(rightChild[cur]);
            }
        }

        for (bool i : checked){
            if (i == false)
                return false;
        }
        return true;
    }
};