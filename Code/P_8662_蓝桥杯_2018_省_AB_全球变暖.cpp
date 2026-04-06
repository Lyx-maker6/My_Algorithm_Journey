#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

struct Node{
    int x,y;
};

int BFS(int sx,int sy,int n,vector<vector<char>>& g,vector<vector<int>>& vis)
{
    queue<Node> q;
    q.push({sx,sy});
    vis[sx][sy] = true;

    
    bool has_safe_land = false; //标记：这个岛是否有“保命”的中心点
    
    while(!q.empty())
    {
        Node cur = q.front();
        q.pop();

        bool is_edge = false; // 检查当前格子是否靠海

        for(int i = 0;i < 4;i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < n)
            {
                //如果旁边有海，这块地就是边缘，会被淹没**************************************
                if (g[nx][ny] == '.') is_edge = true;

                if(g[nx][ny] == '#' && !vis[nx][ny])
                {
                    vis[nx][ny] = true;
                    q.push({nx,ny});
                }
                
            }
        }
        //重要逻辑：如果这块地四周全是陆地，它就是安全的！************************************
        if (!is_edge) has_safe_land = true;
    }
    return !has_safe_land;//如果没发现安全陆地，返回 1 (代表被淹没)
}
int main()
{
    int n;
    cin>>n;
    vector<vector<char>> g(n,vector<char>(n));
    
    for(int i = 0;i < n;i++)
    {
        
        for(int j = 0;j < n;j++)
        {
            cin>>g[i][j];
        }
    }
    vector<vector<int>> vis(n,vector<int>(n,0));
    int cnt = 0;
    
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            if(g[i][j] == '#'&& !vis[i][j])
            {
                if(BFS(i,j,n,g,vis))
                    cnt++;
            }
        }
    }
    cout<<cnt;
        
    return 0;
}