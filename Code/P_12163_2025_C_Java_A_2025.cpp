// 求 1∼20250412 中，有多少个数可以通过改变其数字顺序后含有 2025。
// 例如，5220、21520 可以，而 205、225、2200、222555111 则不行。
// 提示：要求的数就是含有至少 1 个 0、2 个 2、1 个 5 的数。

#include<iostream>
using namespace std;

int main()
{
    int cnt = 0;
    

    for(int i = 2025;i <= 20250412;i++)
    {
        int a[10]={0};
        int tp = i;
        while(tp)
        {
            a[tp%10]++;
            tp /= 10;
        }
        if(a[0]>=1&&a[2]>=2&&a[5]>=1)
            cnt++;
    }
   
    cout<<cnt<<endl;

    return 0;
}
