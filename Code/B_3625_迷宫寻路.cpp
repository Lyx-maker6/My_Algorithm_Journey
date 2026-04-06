#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct Node{
    int x,y;
};

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<char>> g(n+1,vector<char>(m+1));
    
    for(int i = 1;i <= n;i++)
    {
        
        for(int j = 1;j <= m;j++)
        {
            cin>>g[i][j];
        }
    }
    vector<vector<int>> vis(n+1,vector<int>(m+1,0));

    queue<Node> q;
    q.push({1,1});
    vis[1][1] = true;
    int ans = 0;

    //特判：起点或终点是墙，或者地图还没起点就到终点
    if (g[1][1] == '#') {
        cout << "No" << endl;
        return 0;
    }

    while(!q.empty())
    {
        Node cur = q.front();
        q.pop();

        if(cur.x == n && cur.y == m)
        {
            ans = 1;
            break;
        }
        for(int i = 0;i < 4;i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx <= n && nx > 0 && ny <= m && ny > 0 &&
               !vis[nx][ny] && g[nx][ny] != '#')
            {
                vis[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }
    if(ans)
        cout<<"Yes";
    else
        cout<<"No";

    
    

    
    return 0;
}