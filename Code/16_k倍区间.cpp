#include <iostream>
#include <vector>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n,m;
  cin>>n>>m;
  vector<int> nums(n);
  for(int i = 0;i < n;i++) cin>>nums[i];

  int cnt = 0;
    // 左指针 left 代表区间的起点
    for (int left = 0; left < n; left++) {
        long long sum = 0; // 每次更换起点，和都要清零
        // 右指针 right 代表区间的终点
        for (int right = left; right < n; right++) {
            sum += nums[right]; // 累加当前区间的和 [left, right]
            if (sum % m == 0) {
                cnt++; // 如果能整除，计数加 1
            }
        }
    }

  cout<<cnt;
  return 0;
}