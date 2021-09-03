#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <time.h>

using namespace std;

/* class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> vec(k,0);
        if (k == 0) return vec;
        priority_queue<int> q;
        for (int i=0; i<k; i++)
            q.push(arr[i]);
        for (int i=k;i<arr.size();i++){
            if (q.top()>arr[i]){
                q.pop();
                q.push(arr[i]);
            }
        }
        for (int i=0; i<k; i++){
            vec[i] = q.top();
            q.pop();
        }
        return vec;
    }
}; */

// class Solution {
//     int partition(vector<int>& nums, int l, int r) {
//         int pivot = nums[r];
//         int i = l - 1;
//         for (int j = l; j <= r - 1; ++j) {
//             if (nums[j] <= pivot) {
//                 i = i + 1;
//                 swap(nums[i], nums[j]);
//             }
//         }
//         swap(nums[i + 1], nums[r]);
//         return i + 1;
//     }

//     // 基于随机的划分
//     int randomized_partition(vector<int>& nums, int l, int r) {
//         int i = rand() % (r - l + 1) + l;
//         swap(nums[r], nums[i]);
//         return partition(nums, l, r);
//     }

//     void randomized_selected(vector<int>& arr, int l, int r, int k) {
//         if (l >= r) {
//             return;
//         }
//         int pos = randomized_partition(arr, l, r);
//         int num = pos - l + 1;
//         if (k == num) {
//             return;
//         } else if (k < num) {
//             randomized_selected(arr, l, pos - 1, k);
//         } else {
//             randomized_selected(arr, pos + 1, r, k - num);
//         }
//     }

// public:
//     vector<int> smallestK(vector<int>& arr, int k) {
//         srand((unsigned)time(NULL));
//         randomized_selected(arr, 0, (int)arr.size() - 1, k);
//         vector<int> vec;
//         for (int i = 0; i < k; ++i) {
//             vec.push_back(arr[i]);
//         }
//         return vec;
//     }
// };

#include <algorithm>
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (k == 0)
            return vector<int>();
        sort(arr.begin(), arr.end());
        return vector<int>{arr.begin(), arr.begin() + k};
    }
};