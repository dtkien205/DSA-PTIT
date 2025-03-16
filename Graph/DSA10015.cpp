#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct edge {
    int x, y, w;
};

int n, m;
int sz[1005], parent[1005];
vector<edge> adj;

void init()
{
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u)
{
    return (u == parent[u] ? u : parent[u] = Find(parent[u]));
}

bool Union(int u, int v)
{
    u = Find(u), v = Find(v);
    if (u == v)
        return false;
    if (sz[u] < sz[v])
        swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    return true;
}

void Kruskal()
{
    sort(adj.begin(), adj.end(), [](edge a, edge b) -> bool {
        return a.w < b.w;
    });
    int res = 0;
    vector<edge> MST;
    for (int i = 0; i < m; i++) {
        if (MST.size() == n - 1)
            break;
        auto e = adj[i];
        if (Union(e.x, e.y)) {
            res += e.w;
            MST.push_back(e);
        }
    }
    cout << res << endl;
}

void input()
{
    cin >> n >> m;
    adj.clear();
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj.push_back(edge { x, y, w });
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        input();
        init();
        Kruskal();
    }
}