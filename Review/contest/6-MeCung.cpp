#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, par[100005], sz[100005];
bool vs[100005];
vector<int> adj[100005];
bool check;

int Find(int u)
{
    if (u == par[u])
        return u;
    return par[u] = Find(par[u]);
}

bool Union(int u, int v)
{
    u = Find(u), v = Find(v);
    if (u == v)
        return true;
    par[u] = v;
    return false;
}

void dfs(int u, int par)
{
    vs[u] = true;
    for (int v : adj[u]) {
        if (!vs[v]) {
            dfs(v, u);
        } else if (v != par)
            check = true;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            vs[i] = false;
            par[i] = i;
            sz[i] = 1;
            adj[i].clear();
        }

        check = false;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            if (Union(x, y))
                check = true;
        }

        // for (int i = 1; i <= n; i++) {
        //     if (!vs[i])
        //         dfs(i, 0);
        // }

        cout << (check ? "YES\n" : "NO\n");
    }
}