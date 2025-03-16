#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
int parent[1005], sz[1005];

void init()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v)
{
    u = Find(u), v = Find(v);
    if (u == v)
        return false;
    if (sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        init();
        bool hasCycle = false;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            if (!Union(x, y))
                hasCycle = true;
        }
        cout << (hasCycle ? "YES" : "NO") << endl;
    }
}