#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[1005][1005];
int n, m;
int dis[1005][1005];

void BFS(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({ i, j });
    dis[i][j] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x + a[x][y] < n && dis[x + a[x][y]][y] == INT_MAX) {
            dis[x + a[x][y]][y] = dis[x][y] + 1;
            q.push({ x + a[x][y], y });
        }
        if (y + a[x][y] < m && dis[x][y + a[x][y]] == INT_MAX) {
            dis[x][y + a[x][y]] = dis[x][y] + 1;
            q.push({ x, y + a[x][y] });
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                dis[i][j] = INT_MAX;
            }
        }
        BFS(0, 0);
        cout << ((dis[n - 1][m - 1] == INT_MAX) ? -1 : dis[n - 1][m - 1]) << endl;
    }
}