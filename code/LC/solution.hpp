#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>


using namespace std;

// class Solution1 {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> res;
//         if (nums.size() < 3)
//             return res;

//         sort(nums.begin(), nums.end());

//         int len = nums.size();
//         for (int i = 0; i < nums.size() - 2; i++) {
//             if (i > 0 && nums[i] == nums[i-1])
//                 continue;
//             if (nums[i] > 0) return res;
//             int left = i + 1, right = len - 1;
//             while (left < right) {
//                 int sum = nums[i] + nums[left] + nums[right];
//                 if (sum < 0) ++left;
//                 else if (sum > 0) --right;
//                 else {
//                     vector<int> tmp {nums[i], nums[left++], nums[right--]}; 
//                     res.push_back(tmp);
//                     while(left < right && nums[left] == nums[left - 1]) ++left;
//                     while(left < right && nums[right] == nums[right + 1]) --right;  
//                 }
//             }
//         }
//         return res;
//     }
// };

// class Solution2 {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         if (matrix.size() == 0) return;
//         vector<int> raw;
//         vector<int> col;
//         for (int i = 0; i < matrix.size(); ++i) {
//             for (int j = 0; j < matrix[0].size(); ++j) {
//                 if (matrix[i][j] == 0) {
//                     raw.push_back(i);
//                     col.push_back(j);
//                 } 
//             }
//         }
//         for (int raw_index : raw) {
//             for (int j = 0; j < matrix[0].size(); ++j) {
//                 matrix[raw_index][j] = 0;
//             }
//         }
//         for (int col_index : col) {
//             for (int i = 0; i < matrix.size(); ++i) {
//                 matrix[i][col_index] = 0;
//             }
//         }
//         return;
//     }
// };

// class Solution3 {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> res;
//         unordered_map<string, vector<string>> hash;
//         for (int i = 0; i < strs.size(); ++i) {
//             string cur = strs[i];
//             sort(cur.begin(), cur.end());
//             hash[cur].push_back(strs[i]);
//         }

//         for (auto itr = hash.begin(); itr != hash.end(); itr++) {
//             res.push_back(itr->second);
//         }
//         return res;
//     }
// };

// class Solution4 {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int res = 0;
//         if (s.size() < 2)
//             return s.size();
//         int left = 0, right = 0;
//         unordered_set<char> hash;
//         while (right < s.size()) {
//             if (hash.count(s[right]) == 0) {
//                 res = max(res, right - left + 1);
//                 hash.insert(s[right]);
//                 right++;
//             } else {
//                 while (hash.count(s[right]) == 1) {
//                     hash.erase(s[left]);
//                     left++;
//                 }
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int p0 = 0, p2 = n - 1;
//         for (int i = 0; i <= p2; ++i) {
//             while (i <= p2 && nums[i] == 2) {
//                 swap(nums[i], nums[p2]);
//                 --p2;
//             }
//             if (nums[i] == 0) {
//                 swap(nums[i], nums[p0]);
//                 ++p0;
//             }
//         }
//     }
// };

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         priority_queue<pair<int, int>> que;
//         unordered_map<int ,int> hash;
//         for (int itr : nums)
//             hash[itr]++;
//         for (auto itr = hash.begin(); itr != hash.end(); itr++)
//             que.push(make_pair(itr->second, itr->first));
//         vector<int> res;
//         for (int i = 0; i < k; i++) {
//             res.push_back(que.top().second);
//             que.pop();
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int left = 0, right = nums.size() - 1;
//         int mid;
//         while (left <= right) {
//             mid = left + (right - left) / 2;
//             if (nums[mid] == target) {
//                 break;
//             } else if (nums[mid] < target) {
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//         }
//         if (left > right) {
//             return {-1, -1};
//         }
        
//         left = mid;
//         while (left >= 0 && nums[left] == nums[mid])
//             left--;
        
//         right = mid;
//         while (right < nums.size() && nums[right] == nums[mid])
//             right++;
        
//         return {left+1, right-1};
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
//             if (a[0] == b[0])
//                 return b[1] < a[1];
//             return a[0] < b[0];
//             });
        
//         vector<vector<int>> res;
//         int left = intervals[0][0], right = intervals[0][1];
//         for (int i = 1; i < intervals.size(); i++) {
//             if (intervals[i][0] > right) {
//                 res.push_back({left, right});
//                 left = intervals[i][0];
//                 right = intervals[i][1];
//             } else if (intervals[i][1] >= right && intervals[i][0] <= right) {
//                 right = intervals[i][1];
//             }
//         }
//         res.push_back({left, right});
//         return res;
//     }
// };

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         vector<vector<bool>> dp(n, vector<bool>(n, false));
//         string ans;
//         for (int l = 0; l < n; ++l) {
//             for (int i = 0; i + l < n; ++i) {
//                 int j = i + l;
//                 if (l == 0) {
//                     dp[i][j] = true;
//                 } else if (l == 1) {
//                     dp[i][j] = (s[i] == s[j]);
//                 } else {
//                     dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
//                 }
//                 if (dp[i][j] && l + 1 > ans.size()) {
//                     ans = s.substr(i, l + 1);
//                 }
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int left = INT_MAX, mid = INT_MAX;
//         for (auto & itr : nums) {
//             if (itr <= left)
//                 left = itr;
//             else if (itr <= mid) 
//                 mid = itr;
//             else if (itr > mid)
//                 return true;
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int left = 0, right = nums.size() - 1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] == target)
//                 return mid;
            
//             if (nums[left] <= target && target < nums[mid])  // left -> target -> mid  increase;
//                 right = mid - 1;
//             else if (nums[mid] < target && target <= nums[right]) // mid -> target -> right increase;
//                 left = mid + 1;
//             else if (nums[mid] > nums[right] && (target <= nums[right] || target > nums[mid])) // mid -> largest -> right 
//                 left = mid + 1;
//             else
//                 right = mid - 1;
//         }
//         return -1;
//     }
// };

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int right = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             if (i <= right) {
//                 right = std::max(right, i + nums[i]);
//                 if (right >= nums.size() - 1)
//                     return true;
//             }
//         }
//         return false;
//     }
// };

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         vector<int> dp(amount + 1, INT_MAX);
//         dp[0] = 0;
//         for (int i = 1; i <= amount; ++i) {
//             for (int itr : coins) {
//                 if (i - itr >= 0 && dp[i - itr] < INT_MAX)
//                     dp[i] = min(dp[i], dp[i - itr] + 1);
//             }
//         }
//         if (dp.back() == INT_MAX)
//             return -1;
//         return dp.back();
//     }
// };

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         vector<int> dp(nums.size(), 1);  // longest increase substring end with nums[i];
//         for (int i = 1; i < nums.size(); i++) {
//             for (int j = i - 1; j >=0 ; --j) {
//                 if (nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//         }
//         return *max_element(dp.begin(), dp.end());
//     }
// };

// class Solution {
//     unordered_set<int> hash;
// public:
//     bool isHappy(int n) {
//         int cur = 0;
//         while (n > 0) {
//             cur += (n % 10) * (n % 10);
//             n /= 10;
//         }
//         if (cur == 1)
//             return true;
//         if (hash.count(cur))
//             return false;
//         hash.insert(cur);
//         return isHappy(cur);
//     }
// };

// class Solution {
// public:
//     int titleToNumber(string columnTitle) {
//         long res = 0;
//         for (int cur : columnTitle) {
//             res = res *26 + cur - 'A' + 1;
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     double myPow(double x, int n) {
//         if (n == 0)
//             return 1.0;
//         if (n < 0)
//             return 1.0 / myPow(x, -n);
//         double res = 1.0;
//         while (n > 0) {
//             if (n % 2 == 1)
//                 res *= x;
//             x *= x;
//             n /= 2;
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int mySqrt(int x) {
//         int left = 1, right = x / 2;
//         if (x < 2)
//             return x;
//         while (right - left > 1) {
//             int mid = left + (right - left) / 2;
//             if (mid * mid == x)
//                 return mid;
//             else if (mid * mid < x) 
//                 left = mid;
//             else
//                 right = mid - 1;
//         }
//         if (right * right <= x)
//             return right;
//         return left;
//     }
// };

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// class Codec {
// public:

//     // Encodes a tree to a single string.
//     string serialize(TreeNode* root) {
//         if (root == nullptr)
//             return ",null";
//         return "," + to_string(root->val) + serialize(root->left) + serialize(root->right);
//     }

//     // Decodes your encoded data to tree.
//     TreeNode* deserialize(string data) {
//         int idx = 1;
//         return deserialize(data, idx);
//     }

// private:
//     bool getNum(const string& str, int& idx, int& out) {
//         string res = "";
//         for (idx; idx < str.size(); idx++) {
//             if (str[idx] == ',')
//                 break;
//             res.push_back(str[idx]);
//         }
//         idx++;
//         if (res == "null")
//             return false;
//         out = stoi(res);
//         return true;
//     }

//     TreeNode* deserialize(const string& data, int& idx) {
//         if (idx >= data.size())
//             return nullptr;
//         int val = 0;
//         if (getNum(data, idx, val) == false)
//             return nullptr;
//         TreeNode * root = new TreeNode(val);
//         root->left = deserialize(data, idx);
//         root->right = deserialize(data, idx);
//         return root;
//     }
// };

// class Solution {
// public:
//     int hIndex(vector<int>& citations) {
//         sort(citations.begin(), citations.end());
//         int h = 0, i = citations.size() - 1;
//         while (i >= 0 && citations[i] > h) {
//             h++;
//             i--;
//         }
//         return h;
//     }
// };

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> prod = nums;  // 0 -> i product
//         for (int i = 1; i < nums.size(); i++)
//             prod[i] = prod[i] * prod[i - 1];
//         int backword = 1;
//         for (int i = nums.size() - 1; i > 0; i--) {
//             prod[i] = prod[i - 1] * backword;
//             backword *= nums[i];
//         }
//         prod[0] = backword;
//         return prod;
//     }
// };

// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {
//         if (matrix.size() == 0 || matrix[0].size() == 0) {
//             return {};
//         }

//         int rows = matrix.size(), columns = matrix[0].size();
//         vector<int> order;
//         int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
//         while (left <= right && top <= bottom) {
//             for (int column = left; column <= right; column++) {
//                 order.push_back(matrix[top][column]);
//             }
//             for (int row = top + 1; row <= bottom; row++) {
//                 order.push_back(matrix[row][right]);
//             }
//             if (left < right && top < bottom) {
//                 for (int column = right - 1; column > left; column--) {
//                     order.push_back(matrix[bottom][column]);
//                 }
//                 for (int row = bottom; row > top; row--) {
//                     order.push_back(matrix[row][left]);
//                 }
//             }
//             left++;
//             right--;
//             top++;
//             bottom--;
//         }
//         return order;
//     }
// };

// class Solution {
//     unordered_map<int, int> hash; // num -> count;
// public:
//     int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//         int num = nums1.size();
//         for (int i = 0; i < num; i++) {
//             for (int j = 0; j < num; j++) {
//                 hash[nums1[i] + nums2[j]]++;
//             }
//         }
//         int res = 0;
//         for (int i = 0; i < num; i++) {
//             for (int j = 0; j < num; j++) {
//                 if (hash.find(0 - nums3[i] - nums4[j]) == hash.end())
//                     continue;
//                 res += hash[0 - nums3[i] - nums4[j]];
//             }
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int left = 0, right = height.size() - 1;
//         int max_value = 0;
//         while (left < right) {
//             max_value = max(max_value, (right - left)*(min(height[left], height[right])));
//             if (height[left] > height[right])
//                 right--;
//             else
//                 left++;
//         }
//         return max_value;
//     }
// };

// class Solution {
// public:
//     int equalSubstring(string s, string t, int maxCost) {
//         int left = 0, right = 0, cost = 0, max_count = 0;
//         while (right < t.size()) {
//             cost += abs(s[right] - t[right]);
//             if (cost > maxCost) {
//                 while (left <= right && cost > maxCost) {
//                     cost -= abs(s[left] - t[left]);
//                     left++;
//                 }
//             }
//             max_count = max(max_count, right - left + 1);
//             right++;
//         }
//         return max_count;
//     }
// };

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists, 0, lists.size() - 1);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists, const int& left, const int & right) {
        if (left > right)
            return nullptr;
        if (right == left)
            return lists[left];
        else if (left + 1 == right) {
            return mergeKLists(lists[left], lists[right]);
        } else {
            int mid = left + (right - left) / 2;
            return mergeKLists(mergeKLists(lists, left, mid), mergeKLists(lists, mid + 1, right));
        }
        return nullptr;
    }

    ListNode* mergeKLists(ListNode* llist, ListNode* rlist) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while (llist || rlist) {
            if (llist == nullptr) {
                cur->next = new ListNode(rlist->val);
                rlist = rlist->next;
            } else if (rlist == nullptr) {
                cur->next = new ListNode(llist->val);
                llist = llist->next;
            } else if (rlist->val < llist->val) {
                cur->next = new ListNode(rlist->val);
                rlist = rlist->next;
            } else {
                cur->next = new ListNode(llist->val);
                llist = llist->next;
            }
            cur = cur->next;
        }
        return res->next;
    }
};