#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, k;
int par1[200005], par2[200005];

void init()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        par1[i] = i;
        par2[i] = i;
    }
}

int Find(int par[], int u)
{
    if (u == par[u])
        return u;
    return par[u] = Find(par, par[u]);
}

bool Union(int par[], int u, int v)
{
    u = Find(par, u), v = Find(par, v);
    if (u == v)
        return false;
    if (u > v)
        swap(u, v);
    par[v] = u;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    init();
    int x, y;

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        Union(par1, x, y);
    }

    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        Union(par2, x, y);
    }

    map<pair<int, int>, int> mp;

    for (int i = 1; i <= n; i++) {
        x = Find(par1, i), y = Find(par2, i);
        mp[{ x, y }]++;
    }
    for (int i = 1; i <= n; i++)
        cout << mp[{ Find(par1, i), Find(par2, i) }] << ' ';
}