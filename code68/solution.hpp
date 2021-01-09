#include <cstdio>
#include <iostream>
#include <vector>
#include <regex>

using namespace std;

class Solution {
/* public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> out;
        vector<string> temp;
        string cur;
        for (int i = 0; i < words.size(); i++)
        {
            if (cur.size() + words[i].size() > maxWidth)
            {
                out.push_back(cur);
                cur = "";
            }
            cur += (words[i] + " ");
        }
        if (cur.size()>1)
            out.push_back(cur);
        
        int space_num = 0;
        for (int i = 0; i < out.size()-1; i++)
        {
            temp = stringsplit(out[i]);
            if (temp.size()==1)
            {
                cur = temp[0]+string(maxWidth-temp[0].size(), ' ');
                out[i] = cur;
                continue;
            }
            
            space_num = 0;
            for (auto a:temp)
                space_num = space_num + a.size();
            space_num = maxWidth - space_num;

            cur = "";
            if (space_num%(temp.size()-1)==0)
            {
                for (int i = 1; i < temp.size(); i++)
                    cur += temp[i]+string(space_num/(temp.size()-1), ' ');
                out[i] = cur.substr(0, maxWidth);
            }
            else
            {
                for (int i = 1; i < temp.size()-1; i++)
                {
                    cur += temp[i]+string(space_num/(temp.size()-1)+1, ' ');
                    space_num -= (space_num/(temp.size()-1)+1);
                }
                cur += 
            }
            

            cur = temp[0] + string(space_num/(temp.size()-1)+space_num%(temp.size()-1), ' ');

            out[i] = cur.substr(0, maxWidth);
        }
        temp = stringsplit(out[out.size()-1]);
        cur = "";
        for (auto a:temp)
            cur += (a + " ");
        cur += string(maxWidth, ' ');
        out[out.size()-1] = cur.substr(0, maxWidth);
        return out;
    }

    vector<string> stringsplit(string &s){
        regex re(" ");
        vector<string> out(sregex_token_iterator(s.begin(), s.end(), re,-1), sregex_token_iterator());
        return out;
    }
}; */
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<int> len(n, 0);
        len[0] = words[0].size();
        vector<string> res;
        for(int i = 1; i < n; i++)
        {
            len[i] += len[i-1] + words[i].size();
        }
        int point = 0;
        while(point < n)
        {
            int i = point;
            while(i < n && (len[i]-(point == 0 ? 0 : len[point-1])+i-point) <= maxWidth)
            {
                i++;
            }
            i--;
            string temp = "";
            if(i == point)
            {
                temp += words[i];
                temp.append(maxWidth-words[i].size(),' ');
            }
            else
            {	
                int leave = maxWidth - (len[i]-(point == 0 ? 0 : len[point-1]));
                int avg = leave/(i-point);
                int more = leave%(i-point);
                if(i == n-1)
                {
                    avg = 1;
                    more = 0;
                }
                temp += words[point];
                for(int j = point+1; j <= i; j++)
                {
                    if(more > 0)
                    {
                        temp += " ";
                        more--;
                    }
                    temp.append(avg, ' ');
                    temp += words[j];
                }
                if(i == n-1)
                    temp.append(maxWidth-temp.size(), ' ');
            }
            res.push_back(temp);
            point = i+1; 
        }
        return res;
    }
};