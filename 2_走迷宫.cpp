#include <iostream>
#include<vector>
#include <queue>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int g[1000][1000];

struct Node{
  int x,y,step;
};

int main()
{
  // 请在此输入您的代码
  int n,m;
  cin>>n>>m;
  int x0,y0,xn,yn;
  vector<vector<int>> g(n+1,vector<int>(m+1));
  vector<vector<int>> visite(n+1,vector<int>(m+1));
  
  queue<Node> q;
 
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      cin>>g[i][j];
    }
  }

  cin>>x0>>y0>>xn>>yn;
  q.push({x0,y0,0});
  visite[x0][y0] = true;
  int ans = -1; //默认无法到达

  while(!q.empty()){
    Node cur = q.front();
    q.pop();

    if(cur.x == xn && cur.y == yn)
    {
      ans = cur.step;
      break;
    }
      
    for(int i = 0;i < 4;i++)
    {
      int now_x = cur.x + dx[i];
      int now_y = cur.y + dy[i];

      if(now_x > 0 && now_x <= n && now_y > 0 && now_y <= m && g[now_x][now_y] == 1 && !visite[now_x][now_y])//添加一个未被访问
      {
        visite[now_x][now_y] = true;
        q.push({now_x,now_y,cur.step + 1});
      }
    }
  }
  
  cout << ans << endl;

  return 0;
}