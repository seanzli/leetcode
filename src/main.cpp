
#include "../code4/solution.hpp"

int main(){
    Solution *p = new Solution();
    vector<int> num1, num2;
//    num1.push_back(0);
//    num1.push_back(3);
    num2.push_back(1);
 //   num2.push_back(7);

    double out = p->findMedianSortedArrays(num1, num2);

    return 0;
}