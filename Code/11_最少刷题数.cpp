#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 检查：如果这个学生现在的刷题量是 total，能不能达标？
bool check(int total, int original_val, const vector<int>& sorted_b, int n) {
    // 1. 算出比 total 多的人数
    // upper_bound 找第一个比 total 大的位置
    int more_cnt = sorted_b.end() - upper_bound(sorted_b.begin(), sorted_b.end(), total);
    
    // 2. 算出比 total 少的人数
    // lower_bound 找第一个大于等于 total 的位置
    int less_cnt = lower_bound(sorted_b.begin(), sorted_b.end(), total) - sorted_b.begin();
    
    // 3. 特殊细节：如果这个学生原来的分数就在 less_cnt 的范围内，
    // 说明他现在“变强了”，原本那个位置的人数要减 1
    if (original_val < total) {
        less_cnt--; 
    }

    return more_cnt <= less_cnt;
}

int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        int L = 0, R = 100000, ans = 100000;
        
        // 二分搜索这个学生最少要刷多少题
        while (L <= R) {
            int mid = (L + R) / 2;
            if (check(a[i] + mid, a[i], b, n)) {
                ans = mid; // 达标了，记录答案，试着再少刷点
                R = mid - 1;
            } else {
                L = mid + 1; // 不达标，必须多刷点
            }
        }
        cout << ans << (i == n - 1 ? "" : " ");
    }
    return 0;
}