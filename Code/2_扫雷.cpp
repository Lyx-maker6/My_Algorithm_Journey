#include <iostream>
#include <vector>
using namespace std;



int dx[8] = {-1,1,0,0,1,1,-1,-1};
int dy[8] = {0,0,-1,1,1,-1,1,-1};

int main()
{
  // 请在此输入您的代码
  int n,m;
  cin>>n>>m;
  vector<vector<int>> g(n,vector<int>(m));
 
  for(int i = 0;i < n;i++)
  {
    for(int j = 0;j < m;j++) cin>> g[i][j];
  }
  
  for(int i = 0;i < n;i++)
  {
    for(int j = 0;j < m;j++)
    {
      if(g[i][j] == 1) cout<<9<<" ";
      else{
        int cnt = 0;
        for(int k = 0;k < 8;k++)
        {
          int nx = i + dx[k];
          int ny = j + dy[k];
          if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if(g[nx][ny] == 1) cnt++;
          } 
        }
        cout<<cnt<<" ";
      }
    }
    cout<<endl;
  }
  return 0;
}