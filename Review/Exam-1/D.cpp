#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, par[100005], sz[100005];
vector<int> adj[100005];

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        sz[i] = 1;
        par[i] = i;
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
    if (u > v)
        swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
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

    int tmp = 0;
    for (int i = 2; i <= n; i++) {
        int st = Find(1);
        if (Find(i) != st)
            tmp = max(tmp, sz[i]);
    }

    cout << sz[1] + tmp << endl;
}