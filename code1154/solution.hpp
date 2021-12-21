#include <string>

using namespace std;

class Solution {
    int dayOfMonth[12] = {
            31,28,31,30,31,30,31,31,30,31,30,31
    };
    int dayOfMonthLeap[12] = {
            31,29,31,30,31,30,31,31,30,31,30,31
    };
public:
    int dayOfYear(string date) {

        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));

        int* d = dayOfMonth;
        if (yearIsLeap(year))
            d = dayOfMonthLeap;

        int res = 0;
        for (int i = 0; i + 1 < month; ++i) {
            res += d[i];
        }
        res += day;

        return res;
    }

    bool yearIsLeap(int year) {
        return year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
    }
};