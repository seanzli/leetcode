#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <limits.h>

using namespace std;

/* class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        // 记录word是否访问过
        unordered_map<string, int> visitMap; // <word, 查询到这个word路径长度>
        // 初始化队列
        queue<string> que;
        que.push(beginWord);
        // 初始化visitMap
        visitMap.insert(pair<string, int>(beginWord, 1));

        while(!que.empty()) {
            string word = que.front();
            que.pop();
            int path = visitMap[word]; // 这个word的路径长度
            for (int i = 0; i < word.size(); i++) {
                string newWord = word; // 用一个新单词替换word，因为每次置换一个字母
                for (int j = 0 ; j < 26; j++) {
                    newWord[i] = j + 'a';
                    if (newWord == endWord) return path + 1; // 找到了end，返回path+1
                    // wordSet出现了newWord，并且newWord没有被访问过
                    if (wordSet.find(newWord) != wordSet.end()
                            && visitMap.find(newWord) == visitMap.end()) {
                        // 添加访问信息
                        visitMap.insert(pair<string, int>(newWord, path + 1));
                        que.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};
 */
// dfs
class Solution {
    int min_count = INT_MAX;
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        unordered_map<string, bool> visit_map;
        for (string str : wordList)
            visit_map[str] = false;
        if (hash.count(endWord) == 0)
            return 0;
        visit_map[beginWord] = true;
        dfs(beginWord, hash, visit_map, endWord, 1);
        return min_count;        
    }
    
    void dfs(string beginWord, unordered_set<string> & hash, unordered_map<string, bool>& visit, string endWord, int count) {
        if (beginWord == endWord) {
            min_count = min(min_count, count);
            return;
        }
        for (auto itr = hash.begin(); itr != hash.end(); itr++) {
            if (visit[*itr] == false && distanceS(*itr, beginWord) == 1) {
                visit[*itr] = true;
                dfs(*itr, hash, visit, endWord, count + 1);
                visit[*itr] = false;                
            }
        }
    }

    int distanceS(string a, string b) {
        int cur = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                cur++;
        }
        return cur;
    }
};

/* // DFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        unordered_map<string, int> visit_map;
        if (hash.count(endWord) == 0)
            return 0;
        visit_map[beginWord] = 1;
        queue<string> que;
        que.push(beginWord);
        while (que.size()) {
            string cur = que.front(); que.pop();
            for (int i = 0; i < cur.size(); i++) {
                string new_word = cur;
                for (int j = 0; j < 26; j++){
                    new_word[i] = j + 'a';
                    if (new_word == cur)    continue;
                    if (new_word == endWord)    return visit_map[cur] + 1;
                    if (hash.count(new_word) == 1 && visit_map[new_word] == 0) {
                        visit_map[new_word] = visit_map[cur] + 1;
                        que.push(new_word);
                    }
                }
            }
        }
        return 0;
    }
}; */

// double end DFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash(wordList.begin(), wordList.end());
        unordered_map<string, int> visit_map;
        if (hash.count(endWord) == 0)
            return 0;
        if (beginWord == endWord)
            return 1;
        unordered_set<string> begin_set;
        unordered_set<string> end_set;
        begin_set.insert(beginWord);
        visit_map[beginWord] = 1;
        end_set.insert(endWord);
        visit_map[endWord] = 1;
        while (begin_set.size() && end_set.size()) {
            if (end_set.size() < begin_set.size())
                swap(begin_set, end_set);
            unordered_set<string> cur_set;
            for (auto itr = begin_set.begin(); itr != begin_set.end(); itr++) {
                string str = *itr;
                for (int i = 0; i < str.size(); i++) {
                    string new_word = str;
                    for (int j = 0; j < 26; j++) {
                        new_word[i] = j + 'a';
                        if (new_word == str)    continue;
                        if (end_set.count(new_word) == 1)   return visit_map[str] + visit_map[new_word];
                        if (hash.count(new_word) == 1 && visit_map[new_word] == 0) {
                            cur_set.insert(new_word);
                            visit_map[new_word] = visit_map[str] + 1;
                        }
                    }
                }
            }
            begin_set.clear();
            begin_set = cur_set;            
        }
        return 0;
    }
};