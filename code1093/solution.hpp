#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans(0.0, 5);
        ans[0] = 256;
        ans[1] = -1;
        int i = 0, j = count.size() - 1, countL = 0, countR = 0, maxCount = 0;
        long sum = 0, sumCount = 0;
        
        // i表示做指针，j表示右指针，countL表示左边数字数量差值，countR表示右边数字数量差值
        while (i < j) {
            if (count[i] == 0) {
                i++;
                continue;
            }
            if (ans[0] == 256) {
                // 防止出现整个数组只有一个数字的情况
                ans[0] = i;
                ans[1] = i;
                ans[4] = i;
                maxCount = count[i];
            }
            if (count[j] == 0) {
                j--;
                continue;
            }
            ans[1] = max((int)(ans[1]), j);

            if (count[i] >= maxCount) {
                ans[4] = i;
                maxCount = count[i];
            }
            if (count[j] >= maxCount) {
                ans[4] = j;
                maxCount = count[j];
            }
            if (countL == 0) {
                countL = count[i];
            }
            if (countR == 0) {
                countR = count[j];
            }

            if (countL == countR) {
                sum += count[i] * i + count[j] * j;
                sumCount += (count[i] + count[j]);
                countL = 0;
                countR = 0;
                i++;
                j--;
            } else if (countL > countR) {
                sum += count[j] * j;
                sumCount += count[j];
                countL = countL - countR;
                countR = 0;
                j--;
            } else {
                sum += count[i] * i;
                sumCount += count[i];
                countR = countR - countL;
                countL = 0;
                i++;
            }
        }
        if (countL == 0 && countR == 0) {
            ans[3] = (i + j) * 1.0 / 2;
        } else if (countR == 0) {
            ans[3] = i;
        } else {
            ans[3] = j;
        }
        if (i != j) {
            sum += countL * i + countR * j;
            sumCount += (countL + countR);
        } else {
            sum += count[i] * i;
            sumCount += count[i];
        }

        ans[2] = sum * 1.0 / sumCount;
        return ans;
    }
};