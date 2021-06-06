#include <vector>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder, 0, postorder.size() - 1);
    }
    bool verifyPostorder(vector<int>& postorder, int left, int right) {
        if (left >= right)
            return true;
        int i = left;
        for ( ; i < right; i++) {
            if (postorder[i] > postorder[right])
                break;
        }
        int mid_idx = i;
        for ( ; i < right; i++) {
            if (postorder[i] < postorder[right])
                return false;
        }
        return verifyPostorder(postorder, left, mid_idx - 1) && verifyPostorder(postorder, mid_idx, right - 1);
    }
};