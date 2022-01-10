//#include <cstdio>
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Solution {
//    int n;
//    bool flag = false;
//public:
//    bool isAdditiveNumber(string num) {
//        n = num.size();
//        int idx1 = 0;
//        dfs(num,idx1);
//        return flag;
//    }
//    bool dfs(string &num, int idx){
//        for (int i = idx+1; i < n; i++)
//        {
//            string a = num.substr(idx,i-idx);
//            if (a[0] == '0' && a.size()>1)
//                return false;
//            for (int j = i+1; j < n; j++)
//            {
//                string b = num.substr(i, j-i);
//                if (b[0]=='0' && b.size()>1)
//                    continue;
//                string c = addString(a,b);
//                string d = num.substr(j, c.size());
//                if (d[0]=='0' && d.size()>1)
//                    continue;
//                if (c.compare(d)==0){
//                    if (j+c.size()==n){
//                        flag = true;
//                        return flag;
//                    }
//                    else{
//                        if(dfs(num, i))
//                            return flag;
//                    }
//                }
//            }
//        }
//        return flag;
//    }
//
//    string addString(string a , string b){
//        int i = a.size() - 1, j = b.size() - 1, s = 0;
//        string ans;
//        while (i >= 0 || j >= 0 || s) {
//            s += (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
//            ans.insert(begin(ans), s % 10 + '0');
//            s /= 10;
//        }
//        return ans;
//    }
//};

#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    bool helper(string& num, long pre_a, long pre_b, int idx, int count) {
        if (idx >= num.size()) {
            return count > 2;
        }
        long val = 0;
        for (int i = idx; i < num.size(); i++) {
            bool flag = false;
            if (val > pow(10, 17)) {
                break;
            }
            val = val * 10 + num[i] - '0';
            if (count < 2 || pre_a + pre_b == val) {
                flag = helper(num, pre_b, val, i + 1, count + 1);
            }
            if (flag) {
                return true;
            }
            if (val == 0) {
                break;
            }
        }
        return false;
    }
    bool isAdditiveNumber(string num) {
        return helper(num, 0, 0, 0, 0);
    }
};