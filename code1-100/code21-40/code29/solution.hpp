#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         if(dividend == 0) return 0;
//         if(divisor == 1) return dividend;
//         if(divisor == -1){
//             if(dividend>INT_MIN) return -dividend;
//             return INT_MAX;
//         }
//         long a = dividend;
//         long b = divisor;
//         int sign = 1; 
//         if((a>0&&b<0) || (a<0&&b>0)){
//             sign = -1;
//         }
//         a = a>0?a:-a;
//         b = b>0?b:-b;
//         long res = div(a,b);
//         if(sign>0)return res>INT_MAX?INT_MAX:res;
//         return -res;
//     }
//     int div(long a, long b){  // 似乎精髓和难点就在于下面这几句
//         if(a<b) return 0;
//         long count = 1;
//         long tb = b; // 在后面的代码中不更新b
//         while((tb+tb)<=a){
//             count = count + count; // 最小解翻倍
//             tb = tb+tb; // 当前测试的值也翻倍
//         }
//         return count + div(a-tb,b);
//     }
// };

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==1) return INT_MIN;
        if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
        //if(dividend==I)
        int flag=(dividend>0^divisor>0)?-1:1,k=0;
        unsigned a=abs(dividend),b=abs(divisor);
        for(int i=31;i>=0;i--){
            if(a>>i>=b){
                a-=b<<i;
                k+=1<<i;
            }
        }
        return flag==-1?-k:k;
    }
};