#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
int a[505][505], visited[505][505];
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void nhap()
{
    cin >> n >> m;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
}

void DFS(int i, int j)
{
    visited[i][j] = true;
    for (int k = 0; k < 8; k++) {
        int i1 = dx[k] + i;
        int j1 = dy[k] + j;
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] && !visited[i1][j1]) {
            DFS(i1, j1);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        nhap();
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] && !visited[i][j]) {
                    cnt++;
                    DFS(i, j);
                }
            }
        }
        cout << cnt << endl;
    }
}