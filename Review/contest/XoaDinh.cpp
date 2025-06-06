#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, par[200005], sz[200005];
vector<int> p, adj[200005];
bool active[200005];

int Find(int u)
{
    if (u == par[u])
        return u;
    else
        return par[u] = Find(par[u]);
}

bool Union(int u, int v)
{
    u = Find(u), v = Find(v);
    if (u == v)
        return false;
    if (sz[u] > sz[v])
        swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sz[i] = 1;
        active[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        p.push_back(u);
    }

    vector<string> res;
    int cnt = 0;

    for (int i = n - 1; i >= 0; i--) {
        int u = p[i];
        active[u] = true;
        cnt++;

        for (int v : adj[u])
            if (active[v])
                if (Union(u, v))
                    cnt--;

        if (cnt == 1)
            res.push_back("YES");
        else
            res.push_back("NO");
    }

    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << '\n';
}