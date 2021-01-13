#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            // 而我们要对同一树层使用过的元素进行跳过
            if (i > startIndex && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // 去重需要排序
        backtracking(nums, 0);
        return result;
    }

    void recursion(vector<vector<int>> &nums){
        vector<vector<int>> out = nums;
        while (nums[0].size()>0 && nums[1].size()>0)
        {
            return;
        }
        
        
        display(nums);
    }
    void display(vector<vector<int>> &nums){
        cout << "-------" << endl;
        for (int i = 0; i < nums.size(); i++)
        {
            cout <<  i << "--" ;
            for (int j = 0; j < nums[i].size(); j++)
            {
                cout <<  nums[i][j] << ".";
            }
            cout << endl;
        }
    }

    int leo(int num){
        if (num == 1)
            return 1;
        return leo(num-1)*num;
    }

    int fibonacci(int num){
        if (num==1)
            return 1;
        if (num==2)
            return 1;
        return fibonacci(num-1)+fibonacci(num-2);
    }

    int fibonacci_db(int num){
        vector<int> db;
        db.push_back(1);
        db.push_back(1);
        for (int i = 2; i < num; i++)
        {
            db.push_back(db[i-1] + db[i-2]);
        }
        return db[num-1];
    }

    int permutation(vector<int> &nums){
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        cur.clear();
        getVector(nums, 0, out);
        display(out);
        return 0;
    }
    vector<int> cur;
    void getVector(vector<int> &nums, int start, vector<vector<int>>&out){
        out.push_back(cur);
        for (int i = start; i < nums.size(); i++)
        {
            if ((i>start) && (nums[i] == nums[i-1]))
                continue;
            cur.push_back(nums[i]);
            getVector(nums, i+1, out);
            cur.pop_back();
        }
    }
};