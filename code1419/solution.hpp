#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c=0;
        int r=0;
        int o=0;
        int a=0;
        int k=0;
        int re=0;
        bool flag=true;
        for(int i=0; i<croakOfFrogs.size(); i++){
            if (croakOfFrogs[i]=='c') c++;
            if (croakOfFrogs[i]=='r') r++;
            if (croakOfFrogs[i]=='o') o++;
            if (croakOfFrogs[i]=='a') a++;
            re=max(re, c);//遇到k前要判断有多少个c同时存在
            if (croakOfFrogs[i]=='k'){//遇到k就要规约一个croak
                k++;
                if (c>=r && r>=o && o>=a && a>=k){
                c--;
                r--;
                o--;
                a--;
                k--;
                }
                
            }
            if(!(c>=r && r>=o && o>=a && a>=k)){//必须保持任意时刻（c>=r>=o>=a>=k）,才是正确的；否则就是错误的，
                flag=false;
                break;
            }
            
        }
        if (c!=0 || r!=0 || o!=0 || a!=0 ||k!=0) flag=false;//如果最后有剩的字母，也是错误的
        if (flag==true) return re;
        else return -1;
    }
};
