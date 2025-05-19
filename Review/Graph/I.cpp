#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int par[100005];
int n, m;
map<int, int> color[100005]; // dem so mau trong 1 tplt

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        color[i][x] = 1;
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

    if (color[u].size() < color[v].size())
        swap(u, v);
    for (auto [x, y] : color[v])
        color[u][x] += y;
    par[v] = u;

    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    init();
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> z >> x >> y;
        if (z == 1)
            Union(x, y);
        else {
            x = Find(x);
            cout << color[x][y] << endl;
        }
    }
}