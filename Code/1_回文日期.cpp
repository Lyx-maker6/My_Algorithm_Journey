#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int p[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int r[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

int check(int i)
{
    int mon = (i / 100) % 100;
    int year = i / 10000;
    int day = i % 100;
    //不正常月份
    if (mon > 12 || mon < 1)
        return 0;

    //不正常日期>31,>30,>29,>28，这个需要先判断闰年还是平年
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        if (day > r[mon - 1] || day < 1)  return 0;
    }
    else {
        if (day > p[mon - 1] || day < 1)  return 0;
    }
    return 1;
}

//判断是否是回文
// bool isH(int i)
// {
//     string s = to_string(i);
//     string temp = s;
//     reverse(temp.begin(), temp.end());
//     return s == temp;
// }
int main()
{
    // 请在此输入您的代码
    int y1, y2;
    cin >> y1;
    cin >> y2;
    int cnt = 0;
    // for (int i = y1; i <= y2; i++)
    // {
    //   // 先判断回文（字符串操作慢，先做简单回文判断可以加速）
    //     // 或者直接用数字逻辑判断回文
    //     if (isH(i)) {
    //         if (check(i)) cnt++;
    //     }
    // }

    // 只遍历年份的前四位
    for (int i = 1000; i <= 9999; i++) {
        // 构造回文数字：比如 2021 -> 20210000 + 1202 = 20211202
        int t = i, res = i;
        while (t) {
            res = res * 10 + t % 10;
            t /= 10;
        }

        // 检查构造出来的日期是否在范围内且合法
        if (res >= y1 && res <= y2 && check(res)) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}