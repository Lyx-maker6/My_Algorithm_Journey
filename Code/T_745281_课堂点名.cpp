#include <iostream>
using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int a[1005][1005];
    //输入矩阵
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];


    int early = 0;
    int late = 0;  

    for (int i = x + 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1)
                early++;
    early++; 
    

    for (int i = x; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1)
                late++;

    cout << early << " " << late << endl;
    return 0;
}