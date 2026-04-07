#include <iostream>
#include <vector>
using namespace std;
int main()
{
  // 请在此输入您的代码
  // int n,m;
  // cin>>n>>m;
  // vector<int> nums(n);
  // for(int i = 0;i < n;i++) cin>>nums[i];

  // int cnt = 0;
  //   // 左指针 left 代表区间的起点
  //   for (int left = 0; left < n; left++) {
  //       long long sum = 0; // 每次更换起点，和都要清零
  //       // 右指针 right 代表区间的终点
  //       for (int right = left; right < n; right++) {
  //           sum += nums[right]; // 累加当前区间的和 [left, right]
  //           if (sum % m == 0) {
  //               cnt++; // 如果能整除，计数加 1
  //           }
  //       }
  //   }
  int n,m;
  cin>>n>>m;
  vector<int> nums(n);
  for(int i = 0;i < n;i++) cin>>nums[i];
  int cnt = 0;

  //前缀和数组
  vector<long long> preSum(n);
  preSum[0] = nums[0];
  for(int i = 1;i < n;i++) preSum[i] = preSum[i-1] +nums[i];

  for(int i = 0;i < n;i++)
  {
    for(int j = i;j < n; j++)
    {
      if(i == 0 && j == i) 
      {
        if(preSum[i] % m == 0) cnt++;
      }
      else if(i == 0)
      {
        if(preSum[j] % m == 0) cnt++;
      }
      else
      {
        if((preSum[j] - preSum[i-1]) % m == 0) cnt++;
      }
    }
  }

  cout<<cnt;
  return 0;
}