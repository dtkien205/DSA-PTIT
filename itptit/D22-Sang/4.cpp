#include <bits/stdc++.h>
using namespace std;

const int nmax = 2e5 + 5;

int n, m, q, sz[nmax], par[nmax];
vector<pair<int, int>> edges, queries;
int removed[nmax];

int Find(int u)
{
    if (u == par[u])
        return u;
    return par[u] = Find(par[u]);
}

void Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v)
        return;
    if (sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
}

int main()
{
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
        queries.push_back({ e - 1, u });
        removed[e - 1]++;
    }

    for (int i = 0; i < m; i++) {
        if (!removed[i]) {
            auto [u, v] = edges[i];
            Union(u, v);
        }
    }

    vector<int> res(q);
    for (int i = q - 1; i >= 0; i--) {
        auto [e, u] = queries[i];
        res[i] = sz[Find(u)];

        removed[e]--;
        if (!removed[e]) {
            auto [x, y] = edges[e];
            Union(x, y);
        }
    }

    for (int i = 0; i < q; i++)
        cout << res[i] << '\n';
}
