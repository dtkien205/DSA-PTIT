#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, q;
int a[1005][1005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = 1e9;
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x][y] = z;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = min(a[i][j], max(a[i][k], a[k][j]));

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (a[u][v] != 1e9 ? a[u][v] : -1) << endl;
    }
}