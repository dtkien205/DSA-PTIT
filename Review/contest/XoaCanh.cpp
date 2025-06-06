#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int MAX = 2e5 + 5;
int n, m, q, sz[MAX], par[MAX];
vector<pair<int, int>> edges, Q;
int removed[MAX];

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
    if (sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({ u, v });
    }

    for (int i = 0; i < q; i++) {
        int e, u;
        cin >> e >> u;
        Q.push_back({ e - 1, u });
        removed[e - 1]++;
    }

    for (int i = 0; i < m; i++)
        if (!removed[i])
            Union(edges[i].first, edges[i].second);

    vector<int> res;
    for (int i = q - 1; i >= 0; i--) {
        auto [e, u] = Q[i];
        res.push_back(sz[Find(u)]);

        removed[e]--;
        if (!removed[e]) 
            Union(edges[e].first, edges[e].second);
        
    }

    for (int i = q - 1; i >= 0; i--)
        cout << res[i] << endl;
}