#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>
#include <regex>
#include <stack>

using namespace std;

class Solution {
public:
/*     string simplifyPath(string path) {
        vector<string> temp = splitString(path);
        vector<string> out_vector;
        string out = "";
        for (auto i : temp)
        {
            if (i.size()<1)
                continue;
            else if (i.compare("..")==0)
            {
                if (!out_vector.empty())
                    out_vector.pop_back();
                continue;    
            }
            else if (i.compare(".")==0)
            {
                continue;
            }

            out_vector.push_back(i);
        }
        
        if (out_vector.size()<1)
            return "/";
        
        for (int i = 0; i < out_vector.size(); i++)
            out = out + "/" + out_vector[i];
        
        return out;
    }

    vector<string> splitString(const string &in){
        regex re("/+");
        vector<string> out(sregex_token_iterator(in.begin(), in.end(), re, -1), 
            sregex_token_iterator());
        return out;
    } */
        string simplifyPath(string path) {
        string res;
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == '.')
            {
                if (i == path.size() - 1 || path[i + 1] == '/')
                {
                    ++i;
                    continue;
                }
                if (path[i + 1] == '.')
                {
                    if (i + 1 < path.size() - 1 && path[i + 2] != '/')
                    {
                        while (i < path.size() && path[i] != '/')
                        {
                            res.push_back(path[i]);
                            ++i;
                        }
                        --i;
                        continue;
                    }
                    ++i;
                    if (res.size() <= 1)
                    {
                        continue;
                    }
                    else
                    {
                        res.pop_back();
                        while (res.back() != '/')
                        {
                            res.pop_back();
                        }
                        continue;
                    }
                }
            }
            if (path[i] == '/' && !res.empty() && res.back() == '/')
            {
                continue;
            }
            res.push_back(path[i]);
        }
        if (res.size() > 1 && res.back() == '/')
        {
            res.pop_back();
        }
        return res;
    }
};

/* 常用函数：
regex_match：全文匹配，要求整个字符串符合正则表达式的匹配规则。用来判断一个字符串和一个正则表达式是否模式匹配，如果匹配成功则返回true，否则返回false。

regex_search：搜索匹配，根据正则表达式来搜索字符串中是否存在符合规则的子字符串。

regex_replace：替换匹配，即可以将符合匹配规则的子字符串替换为其他字符串。要求输入一个正则表达式，以及一个用于替换匹配子字符串的格式化字符串。这个格式化字符串可以通过转义序列引用匹配子字符串中的部分内容。

语法规则：
1. \ 表示将下一字符标记为特殊字符、转义字符；

2. ^ 表示字符串的开始，匹配输入字符串开始的位置；

3. ^$ 表示字符串的结尾，匹配输入字符串结尾的位置；

4. . 表示匹配除换行符" \n "以外的任意字符；

5. \w 表示任意字母、数字、下划线 ；

6. \s 表示任意空白符(tab也包含在内)；

7. \d 表示匹配单个数字字符，\D 表示非数字字符匹配；

8. [] 表示一个字符集合，匹配指定范围内的任何字符，例如[a-z]表示字母a~z所组成的集合；

9. []中使用^来表示集合的补集，匹配不在指定的范围内的任何字符，例如[^1-3]表示除1 2 3以外数字；

10. [[:alpha:]] 表示任何字母；

11. [[:alnum:]] 表示任何字母和数字；

12. regex::icase 表示匹配时忽略大小写；

13. {n} 表示正好匹配 n 次前面的字符或表达式，例如"hello{6}",匹配字符串中符合第二个l后边有6个o的子字符串；

14. {n, } 表示至少匹配 n 次前面的字符或表达式；

15. {n,m} 表示匹配至少 n 次，至多 m 次前面的字符或表达式；

16. * 表示零次或多次匹配前面的字符或子表达式，等效于{0, }；

17. + 表示一次或多次匹配前面的字符或子表达式；

18. ? 表示零次或一次匹配前面的字符或子表达式；

19. \t \n \r这些平时非常常见，分别表示制表符匹配、换行符匹配、回车符匹配。 */