#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, sz[100005];
bool vs[100005];
vector<int> adj[100005];

void dfs(int u)
{
    vs[u] = true;
    sz[u] = 1;
    for (int v : adj[u]) {
        if (!vs[v]) {
            dfs(v);
            sz[u] += sz[v];
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << sz[i] << ' ';
}