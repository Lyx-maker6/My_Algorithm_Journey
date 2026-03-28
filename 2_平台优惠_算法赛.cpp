#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    // 请在此输入您的代码
    //这个题用了贪心算法，首先找到最大的数，然后找到第二大的数，最后输出两者的和。
    int n;
    cin >> n;
    vector<int> nums(n);
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        sum+=nums[i];
    }
    sort(nums.begin(),nums.end(),greater<int>());

    int dicout = 0;
    for(int i = 2;i < n;i+=3)
    {
      dicout+=nums[i];
    }
    cout << sum - dicout << endl;
    
    return 0;
}