#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(int &a,int &b){
        return abs(a)>abs(b);
    }
    int largestSumAfterKNegations(vector<int>& A, int &K) {
        sort(A.begin(),A.end(),cmp);
        int len=A.size();
        for(int i=0; K>=1 && i<len-1; i++){
            if(A[i]<0) {
                A[i]=-A[i];
                K--;   
            }
        }
        while(K>=1){
            A[len-1]=-A[len-1];
            K--;
        }
        int result=0;
        for(int i=0;i<len;i++){
            result=result+A[i];
        }
        return result;
    }
};