#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, q;
int par[10005], sz[10005];

void init()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
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
    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 1)
            Union(x, y);
        else
            cout << (Find(x) != Find(y) ? "No" : "Yes") << endl;
    }
}