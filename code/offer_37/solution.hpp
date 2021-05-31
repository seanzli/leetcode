#include <string>
#include <vector>
#include <queue>

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "[";
        queue<TreeNode*> que;
        if (root == nullptr)
            return "[]";
        que.push(root);
        int count = 1;
        while (que.size() && count > 0) {
            int n = que.size();
            count = 0;
            for (int i = 0; i < n; ++i) {
                TreeNode* cur = que.front(); que.pop();
                if (cur == nullptr) {
                    res += "null,";
                    continue;
                }
                res += to_string(cur->val);
                res += ",";
                que.push(cur->left);
                que.push(cur->right);
                if (cur->left != nullptr)
                    count++;
                if (cur->right != nullptr)
                    count++;
            }
        }
        res.back() = ']';
        return res;
    }

    vector<TreeNode*> vec;
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 1;
        while (idx < data.size() && data[idx] != ']') {
            TreeNode* cur = getNextNode(data, idx);
            vec.push_back(cur);
        }

        if (vec.size() == 0)
            return nullptr;

        idx = 0;
        queue<TreeNode*> que;
        que.push(vec[idx++]);
        while (idx < vec.size()) {
            TreeNode* cur = que.front(); que.pop();
            cur->left = vec[idx++];
            if (idx == vec.size())
                break;
            cur->right = vec[idx++];
            if (idx == vec.size())
                break;
            if (cur->left != nullptr)
                que.push(cur->left);
            if (cur->right != nullptr)
                que.push(cur->right);
        }
        return vec[0];
    }

    TreeNode* getNextNode(string data, int& idx) {
        if (idx == data.size() || data[idx] == ']')
            return nullptr;
        string cur = "";
        if (data[idx] == '[' || data[idx] == ',')
            idx++;
        while (idx < data.size() && data[idx] != ',' && data[idx] != ']') {
            cur += data[idx++];
        }
        if (cur == "null")
            return nullptr;
        return new TreeNode(stoi(cur));
    }
}; */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string str;
        if(root == nullptr)
            return str;
        queue<TreeNode*> queue1;
        queue1.push(root);
        while(!queue1.empty())
        {
            TreeNode *pNode = queue1.front();
            queue1.pop();
            if(pNode == nullptr)
                str.push_back('\0');
            else
            {
                str += to_string(pNode->val);   // 不能用str.push_back('0'+pNode->val);
                str.push_back(','); // 注意这个必须有，用来区分不同数字！
            }
            if(pNode != nullptr)
            { 
                queue1.push(pNode->left);
                queue1.push(pNode->right);
            }
        }
        while(str.back() == '\0')
            str.pop_back();
        return str;
    }
    // 如果是完全二叉树，下标为i的左子树下标为i*2+1，右子树下标为i*2+2
    // 但这里不是，所以不能用下标的方法查找左右子树
    // 反序列化依然需要依照BFS的方式完成树的构建
    // 这个问题的本质是用层序遍历的方式建立二叉树
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data.empty())
            return nullptr;
        int index = 0;
        bool isNegative = false;    // 判断正负
        int num = 0;
        if(data[index] == '-')
        {
            index++;
            isNegative = true;
        }
        num = 0;
        while(data[index] != ',')
            num = num*10 + data[index++] - '0';
        if(isNegative)
            num = -num;
        TreeNode *root = new TreeNode(num);
        queue<TreeNode*> queue1;
        queue1.push(root);
        while(!queue1.empty())
        {
            TreeNode *pNode = queue1.front();
            queue1.pop();
            if(data[++index] == '\0')
            {
                pNode->left = nullptr;
            }
            else
            {
                // 首先判断正负
                isNegative = false;
                if(data[index] == '-')
                {
                    index++;
                    isNegative = true;
                }
                // 注意，如果数字不止一位，需要先求出这一位数字再赋值
                num = 0;
                while(data[index] != ',')
                    num = num*10 + data[index++] - '0';
                if(isNegative)
                    num = -num;
                pNode->left = new TreeNode(num);
                queue1.push(pNode->left);
            }
            if(data[++index] == '\0')
            {
                pNode->right = nullptr;
            }
            else
            {
                bool isNegative = false;
                if(data[index] == '-')
                {
                    index++;
                    isNegative = true;
                }
                num = 0;
                while(data[index] != ',')
                    num = num*10 + data[index++] - '0';
                if(isNegative)
                    num = -num;
                pNode->right = new TreeNode(num);
                queue1.push(pNode->right);
            }
        }
        return root;
    }
};