#include <iostream>
using namespace std;

int arr[10];
bool check(int n)
{
    
    while(n)
    {
        int tp = n % 10;
        arr[tp] --;
        n/=10;
        if(arr[tp%10]<0) return false;
    }
    return true;
}
int main()
{
    
    for(int i=0;i<10;i++) arr[i]=2021;
    for(int i=1;;i++)
    {
        if(!check(i)) 
        {
            cout << i-1 << endl;
            break;
        }
    }

    return 0;
}