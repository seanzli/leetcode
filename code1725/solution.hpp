#include <algorithm>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

//class Solution {
//public:
//    int countGoodRectangles(vector<vector<int>>& rectangles) {
//        map<int, int> hash; // square , count;
//        for (const auto& itr : rectangles)
//            ++hash[std::min(itr[0], itr[1])];
//
//        return hash.rbegin()->second;
//    }
//};

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        auto& itr = *max_element(rectangles.begin(), rectangles.end(), [](const vector<int>& a, const vector<int>& b){
            return min(a[0], a[1]) > min(b[0], b[1]);
        });
        return count_if(rectangles.begin(), rectangles.end(), [&](const vector<int>& vec) {
            return min(vec[0], vec[1]) == min(itr[0], itr[1]);
        });
    }
};