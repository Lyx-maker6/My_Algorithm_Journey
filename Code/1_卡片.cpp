#include<iostream>
#include<vector>
using namespace std;

int nums[10];
//检查
bool check(int n)
{
    while(n)
    {
        int tp = n % 10;
        nums[tp]--;
        if(nums[tp]<0)  return false;
        n/=10;
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<10;i++) nums[i]=2021;
    for(int i = 0; ;i++)
    {
        if(!check(i))
        {
            cout<<i-1;
            break;
        }
    }

    return 0;
}