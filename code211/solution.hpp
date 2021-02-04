#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Tril
{
    bool is_end;
    vector<Tril*> m_vec;
    Tril(){
        for (int i = 0; i < 26; i++)
            m_vec.push_back(nullptr);        
    }
};


class WordDictionary {
private:
    Tril *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Tril;
    }
    
    void addWord(string word) {
        Tril *head = root;
        for (char cur : word){
            if (head->m_vec[cur-'a']==nullptr)
                head->m_vec[cur-'a'] = new Tril;
            head = head->m_vec[cur-'a'];
        }
        head->is_end = true;
    }
    
    bool search(string word) {
        return dsf(word, 0, root);
    }

    bool dsf(string& word, int idx, Tril* root){
        if (root == nullptr)
            return false;
        if (idx == word.size()-1){
            if (word[idx]=='.'){
                for (int i = 0;i<root->m_vec.size(); i++){
                    if (root->m_vec[i] && root->m_vec[i]->is_end)
                        return true;
                }
                return false;
            }
            return  root->m_vec[word[idx]-'a'] && root->m_vec[word[idx]-'a']->is_end;
        }
        if (word[idx] == '.'){
            for (int i = 0 ;i < root->m_vec.size(); i++){
                if (dsf(word, idx+1, root->m_vec[i]))
                    return true;
            }
        } else {
            return dsf(word, idx+1, root->m_vec[word[idx]-'a']);
        }
        return false;
    }
};