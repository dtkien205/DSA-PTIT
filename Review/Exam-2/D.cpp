#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, x, y, par[1005];
vector<int> adj[1005];
bool vs[1005];

void dfs(int u)
{
    vs[u] = 1;
    for (int v : adj[u]) {
        if (!vs[v])
            dfs(v);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m >> x >> y;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            memset(vs, false, sizeof(vs));
            vs[i] = true;
            dfs(x);
            if (!vs[y])
                res++;
        }

        cout << res << endl;
    }
}