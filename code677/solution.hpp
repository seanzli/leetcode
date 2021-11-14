#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <memory.h>

// using namespace std;

// class MapSum {
// private:
//     bool isEnd; // 是否为最后一个字母
//     MapSum* next[26]; // 字母表
//     int value; // 若为最后一个字母，其对应的值
    
//     // 深度优先遍历算法
//     int dfs(MapSum* root) { 
//         if(!root) return 0; // 递归基：如果当前访问的MapSum为空，则直接返回0
        
//         int res = 0;
//         if(root->isEnd) res += root->value; // 若当前节点不为空且isEnd，则加上其值
//         for(MapSum* cur : root->next) { // 再遍历当前节点的next数组中所有的MapSum
//             res += dfs(cur);
//         } 

//         return res;
//     }
// public:
//     /** Initialize your data structure here. */
//     MapSum() {
//         isEnd = false;
//         memset(next, 0, sizeof(next));
//         value = 0;
//     }
    
//     void insert(string key, int val) {
//         MapSum* node = this;
//         for(char ch : key) {
//             if(node->next[ch - 'a'] == NULL) {
//                 node->next[ch - 'a'] = new MapSum();
//             }
//             node = node->next[ch - 'a'];
//         }
//         node->isEnd = true;
//         node->value = val; // 相比较正常的前缀树，只是新增了一个value属性
//     }
    
//     int sum(string prefix) {
//         MapSum* node = this;
//         for(char ch : prefix) {
//             if(node->next[ch - 'a'] == NULL) return 0;
//             node = node->next[ch - 'a'];
//         }
//         return dfs(node);
//     }
// };

#include <unordered_map>

using namespace std;

class MapSum {
public:
    MapSum() {

    }
    
    void insert(string key, int val) {
        cnt[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        for (auto & [key,val] : cnt) {
            if (key.substr(0, prefix.size()) == prefix) {
                res += val;
            }
        }
        return res;
    }
private:
    unordered_map<string, int> cnt;
};