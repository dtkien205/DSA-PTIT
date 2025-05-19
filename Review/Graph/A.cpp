#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, k, res, cnt;
int a[1005][1005];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void dfs(int i, int j)
{
    cnt++;
    a[i][j] = 0;
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1]) {
            dfs(i1, j1);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cnt = 0;
            if (a[i][j]) {
                dfs(i, j);
                res = max(cnt, res);
            }
        }
    }
    cout << res << endl;
}