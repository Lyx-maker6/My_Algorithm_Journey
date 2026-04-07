#include <iostream>
#include<iomanip>
using namespace std;

int n;
bool vis[12];
int ans[12];

void dfs(int num)
{
    if(num == n + 1)
    {
        for(int i = 1;i <= n;i++)
        {
            cout<<setw(5)<<ans[i];
        }
        cout<<endl;
    }

    for(int i = 1;i <= n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            ans[num] = i;
            dfs(num + 1);
            vis[i] = false;
        }
    }
}

int main()
{
    cin>>n;
    dfs(1);
    return 0;
}
