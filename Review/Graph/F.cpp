#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, x;
int par[100005], sz[100005];

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        par[i] = i;
        sz[i] = x;
    }
}

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
    if (sz[u] > sz[v])
        swap(u, v);
    sz[v] = min(sz[v], sz[u]);
    par[u] = v;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    init();
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }

    ll res = 0;
    for (int i = 1; i <= n; i++) {
        int x = Find(i);
        res += sz[x];
        sz[x] = 0;
    }
    cout << res;
}