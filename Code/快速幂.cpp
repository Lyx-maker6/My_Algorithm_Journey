#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll fastPow(ll a,ll n ,ll mod)
{
    ll ans=1;
    a%=mod;
    
    while(n)
    {
        if(n&1)//只要指数还没被“拆”完，就继续循环，如果是 1，把当前的“翻倍底数”乘进结果
         ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;//指数二进制右移一位，丢弃已处理的末位
    }
    return ans;
}

ll modInverse(ll a, ll mod) {
    return fastPow(a, mod - 2, mod);
}

int main()
{
    return 0;
}
