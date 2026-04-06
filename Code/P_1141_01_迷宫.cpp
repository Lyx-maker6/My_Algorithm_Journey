#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// 方向数组：上下左右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int n, m;
string g[1005];          // 存储迷宫地图
int vis[1005][1005];     // 身份证：存储每个格子属于哪个“圈子编号”
int ans[1000005];        // 账本：存储每个“圈子编号”的总人数
int block_id = 0;        // 自动递增的圈子编号

// BFS：负责把一个圈子的人全部找出来，并发放相同的“身份证号”
void bfs(int sx, int sy) {
    block_id++; // 发现新圈子，编号加 1
    int count = 0;
    queue<pair<int, int>> q;

    q.push({sx, sy});
    vis[sx][sy] = block_id; // 给起点发身份证

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        count++; // 找到一个小伙伴，人数加 1

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            // 1. 越界检查
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                // 2. 没领过证 (vis == 0) 且 满足 01 跳跃规则 (数字不同)
                if (!vis[nx][ny] && g[cur.first][cur.second] != g[nx][ny]) {
                    vis[nx][ny] = block_id; // 发放同样的身份证
                    q.push({nx, ny});
                }
            }
        }
    }
    ans[block_id] = count; // 把这个圈子的总人数记在账本上
}

int main() {
    // 加快输入输出速度，应对 10 万次询问
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> g[i];

    // 第一阶段：全地图普查（染色记账）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) { // 如果这个格子还没进圈
                bfs(i, j);    // 启动 BFS 把它所在的圈子全数出来
            }
        }
    }

    // 第二阶段：快速回答询问（查账本）
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;
        // 注意：题目给的坐标从 1 开始，我们的数组从 0 开始，要减 1
        int id = vis[r - 1][c - 1];
        cout << ans[id] << "\n";
    }

    return 0;
}