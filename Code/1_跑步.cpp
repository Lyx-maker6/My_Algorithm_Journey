#include <iostream>
using namespace std;

int main() {
    // 2022年每个月的天数
    int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int weekday = 6; // 1月1日是周六
    int ans = 0;

    for (int m = 1; m <= 12; m++) { // 遍历月
        for (int d = 1; d <= months[m]; d++) { // 遍历日
            
            // 条件1：周六(6)或周日(7)
            // 条件2：日期是 1, 11, 21, 31
            if (weekday == 6 || weekday == 7 || d == 1 || d == 11 || d == 21 || d == 31) {
                ans++;
            }

            // 维护周几的变化
            weekday++;
            if (weekday > 7) weekday = 1;
        }
    }

    cout << ans << endl;
    return 0;
}