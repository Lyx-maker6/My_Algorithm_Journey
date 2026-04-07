#include <iostream>
#include<vector>
using namespace std;

int n;
int col[25], row[25]; 
bool vis[25][25];     
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
vector<int> path;     //存储路径编号

void dfs(int x,int y)
{
  if(x == n - 1 && y == n - 1)
  {
    for(int i = 0;i < n;i++)
    {
      if(row[i] != 0 || col[i] != 0) return;
    }
    for(int i = 0;i < path.size();i++)
    {
      cout<<path[i]<<" ";
    }
    cout << endl;
    return;
  }

  for(int i = 0;i < 4;i++)
  {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny])
    {
      //剪枝判断：如果这一行或这一列的箭已经射完了，就不能往这走了
      if (row[nx] <= 0 || col[ny] <= 0) continue;

      vis[nx][ny] = true;
      row[nx]--;
      col[ny]--;
      path.push_back(nx * n + ny);

      dfs(nx,ny);

      // --- 【回溯动作】：撤销标记、还箭、删路径 ---
      path.pop_back();
      vis[nx][ny] = false;
      row[nx]++;
      col[ny]++;
    }
  }

}

int main()
{
  // 请在此输入您的代码]
  cin>>n;
  
  for(int i  = 0;i < n;i++) cin>>col[i];
  for(int i  = 0;i < n;i++) cin>>row[i];

  vis[0][0] = true;
  col[0]--; 
  row[0]--;
  path.push_back(0);

  dfs(0, 0);

  return 0;
}