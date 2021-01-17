#include <vector>
#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int string_length = s.size();
        int vector_length = words.size();
        int substr_length = words[0].size();
        int i,j;
        char *p = (char*)s.c_str();
        vector<int> out;
        for (i = 0; i < string_length-vector_length*substr_length+1; i++)
        {
            for (j = 0; j < vector_length; j++)
            {
                if ((s[i] == words[j][0]) && (stringCheck(p+i,j,words)))
                {
                    out.push_back(i);
                    break;
                }
            }
        }
        return out;
    }

    bool stringCheck(char* p, int idx, vector<string> words){
        int n = words[0].size();
        int w = words.size();
        int d = 0;
        for (int i = 1; i < words[idx].size(); i++)
        {
            if (p[i]!=words[idx][i])
                return false;
        }
        words[idx] = "";d++;
        bool b_sub_check = false;
        while (1)
        {
            b_sub_check = false;
            for (int i = 0; i < w; i++)
            {
                if(stringCheck2(p+d*n,words[i]))
                {
                    words[i]="";d++;
                    b_sub_check = true;
                }
            }
            if (b_sub_check==false)
                break;
        }
        if (w==d)
            return true;
        else
            return false;        
    }
    bool stringCheck2(char *p, string s)
    {
        if (s.size()<1)
            return false;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (p[i]!=s[i])
                return false;
        }
        return true;
    }
    /* vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty()) return res;
        int n = s.size(), m = words.size(), w = words[0].size();
        unordered_map<string, int> tot;
        for(string& word: words)
            tot[word]++;
        // 枚举余数？
        for(int i = 0; i < w; i++)
        {
            int suc = 0;
            unordered_map<string, int> window;
            for(int j = i; j + w <= n; j += w)
            {
                if(j >= i + m * w)
                {
                    string cur = s.substr(j - m * w, w);
                    window[cur]--;
                    if(window[cur] < tot[cur]) 
                        suc--;
                }
                string cur = s.substr(j, w);
                window[cur] ++;
                if(window[cur] <= tot[cur])
                    suc++;
                if(suc == m)
                    res.push_back(j - (m - 1) * w);
            }
        }
        return res;
    } */
};