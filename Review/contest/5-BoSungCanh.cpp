#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, sz[100005], par[100005];

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
        return false;
    if (sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        sz[i] = 1;
        par[i] = i;
    }

    int mx = 0;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }

    for (int i = 1; i <= n; i++) {
        if (Find(i) != Find(1))
            mx = max(mx, sz[i]);
    }
    cout << sz[1] + mx;
}