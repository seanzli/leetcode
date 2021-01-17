#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    vector<TreeNode*> out;
    vector<vector<int>> lists;
    vector<TreeNode*> generateTrees(int n) {
        permutation(n);
        for (int i = 0; i < lists.size(); i++)
            genTree(lists[i]);
        return check(out);
    }
    vector<int> flag;
    vector<int> cur;
    void permutation(int n){
        flag = vector<int>(n);
        for (int i = 1; i <= n; i++)
        {
            flag[i-1]=1;
            cur.clear();
            cur.push_back(i);
            permutation2(1,n);
            cur.pop_back();
            flag[i-1]=0;
        }
    }
    void permutation2(int l, int n){
        if (l==n)
            lists.push_back(cur);

        for (int i = 1; i <= n; i++)
        {
            if (flag[i-1]==0)
            {
                cur.push_back(i);
                flag[i-1]=1;
                permutation2(l+1,n);
                cur.pop_back();
                flag[i-1]=0;
            }
        }
        
    }
    void genTree(vector<int> &num){
        TreeNode *cur_root = new TreeNode(num[0]);
        for (int i=1;i<num.size();i++){
            if(!insertTree(cur_root, num[i]))
                return;
        }
        out.push_back(cur_root);
    }
    bool insertTree(TreeNode* root, int num){
        if (root==nullptr)
        {
            root = new TreeNode(num);
            return true;
        }
        
        if (root->val > num)
        {
            if (root->left)
                return insertTree(root->left, num);
            else
                root->left = new TreeNode(num);
            return true;        
        }
        else
        {
            if (root->right)
                return insertTree(root->right, num);
            else
                root->right = new TreeNode(num);
            return true;
        }
    }
    vector<TreeNode*> check(vector<TreeNode*> &in){
        unordered_map<double, int> hash;
        vector<TreeNode*> out;
        double cur_num;
        for (int i = 0; i < in.size(); i++)
        {
            cur_num = 0.0;
            getTreeNum(in[i], cur_num);
            if (hash.find(cur_num)==hash.end())
            {
                hash[cur_num]++;
                out.push_back(in[i]);
            }
        }
        return out;
    }
    void getTreeNum(TreeNode* root, double &out){
        if (root==nullptr)
            return;
        out = out*10.0 + root->val;
        getTreeNum(root->left, out);
        getTreeNum(root->right, out);
    }
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return { nullptr };
        }
        vector<TreeNode*> allTrees;
        // 枚举可行根节点
        for (int i = start; i <= end; i++) {
            // 获得所有可行的左子树集合
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);

            // 获得所有可行的右子树集合
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

            // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
            for (auto& left : leftTrees) {
                for (auto& right : rightTrees) {
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.emplace_back(currTree);
                }
            }
        }
        return allTrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (!n) {
            return {};
        }
        return generateTrees(1, n);
    }
};