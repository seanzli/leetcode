#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
/*     vector<string> restoreIpAddresses(string s) {
        vector<string> out;
        string cur = "";
        if ((s.size()<4) || (s.size()>16))
            return out;
        int cur_num;
        for (int i = 1; i < 4; i++)
        {
            if (string2num(s.substr(0,i))<0)
                continue;
            cur = s.substr(0,i) + ".";
            for (int i2 = i+1; i2 < i+4; i2++)
            {
                if (i2>=s.size())
                    break;
                if (string2num(s.substr(i,i2-i))<0)
                    continue;
                cur = cur + s.substr(i,i2-i) + ".";
                for (int i3 = i2+1; i3 < i2+4; i3++)
                {
                    if (i3>=s.size())
                        break;
                    if ((string2num(s.substr(i2,i3-i2))<0) || (string2num(s.substr(i3))<0))
                        continue;
                    cur = cur + s.substr(i2,i3-i2) + "." + s.substr(i3);
                    out.push_back(cur);
                    cur = cur.substr(0, i2+2);
                }
                cur = cur.substr(0, i+1);
            }
        }
        return out;
    }
    int string2num(string s){ // string 2 num is valid return 0-255 ,otherwise return -1
        if (s.size()>3)
            return -1;   
        if ((s.size()==3) && ((s[0]=='0') || (s[0]>'3')))
            return -1;
        if ((s.size()==2) && (s[0]=='0'))
            return -1;
        double out = 0.0;
        for (int i = 0; i < s.size(); i++)
            out = out*10.0 + s[i] - '0';
        return (int)(out>255?-1:out);
    } */
    
private:
    vector<string> result;// 记录结果
    // startIndex: 搜索的起始位置，pointNum:添加逗点的数量
    void backtracking(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) { // 逗点数量为3时，分隔结束
            // 判断第四段子字符串是否合法，如果合法就放进result中
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) { // 判断 [startIndex,i] 这个区间的子串是否合法
                s.insert(s.begin() + i + 1 , '.');  // 在i的后面插入一个逗点
                pointNum++;
                backtracking(s, i + 2, pointNum);   // 插入逗点之后下一个子串的起始位置为i+2
                pointNum--;                         // 回溯
                s.erase(s.begin() + i + 1);         // 回溯删掉逗点
            } else break; // 不合法，直接结束本层循环
        }
    }
    // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0开头的数字不合法
                return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        backtracking(s, 0, 0);
        return result;
    }
};