#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
string g[105]; // 用 string 数组存 N*M 
//八个方向
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void dfs(int x, int y) {
    g[x][y] = '.'; // 踩灭它
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == 'W') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> g[i];

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'W') {
                cnt++;   // 发现一个新水坑
                dfs(i, j); // 把这个水坑里所有的 W 全部抹掉
            }
        }
    }
    cout << cnt << endl;
    return 0;
}