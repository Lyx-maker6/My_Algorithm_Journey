#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 辗转相除法求最大公约数
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    // 1. 排序
    sort(a.begin(), a.end());

    // 2. 求所有相邻差值的最大公约数
    long long d = 0;
    for (int i = 1; i < N; i++) {
        d = gcd(d, a[i] - a[i - 1]);
    }

    // 3. 特判公差为 0 的情况（所有数字相等）
    if (d == 0) {
        cout << 0 << endl;
    } else {
        // 4. 计算总项数 = (最大值 - 最小值) / d + 1
        long long total_count = (a[N - 1] - a[0]) / d + 1;
        // 5. 补多少个数 = 总项数 - 已有的个数 N
        cout << total_count - N << endl;
    }

    return 0;
}