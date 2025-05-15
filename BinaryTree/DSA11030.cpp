#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, res;
vector<int> adj[1005];
bool visited[1005], ok;

void dfs(int u, int v, int cnt)
{
    if (ok)
        return;
    visited[u] = true;
    if (u == v) {
        res = cnt;
        ok = true;
        return;
    }
    for (auto x : adj[u]) {
        if (!visited[x])
            dfs(x, v, cnt + 1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 1; i <= n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int q;
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            memset(visited, false, sizeof(visited));
            ok = false;
            dfs(u, v, 0);
            cout << res << endl;
        }
    }
}