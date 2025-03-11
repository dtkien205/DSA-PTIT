#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
vector<int> adj[1005], t_adj[1005];
bool visited[1005];
stack<int> Topo;

void dfs1(int u)
{
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs1(v);
    }
    Topo.push(u);
}

void dfs2(int u)
{
    visited[u] = true;
    for (int v : t_adj[u]) {
        if (!visited[v])
            dfs2(v);
    }
}

int Kosaraju()
{
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs1(i);
    }
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    while (!Topo.empty()) {
        int u = Topo.top();
        Topo.pop();
        if (!visited[u]) {
            cnt++;
            dfs2(u);
        }
    }
    return cnt == 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            t_adj[i].clear();
        }
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            t_adj[y].push_back(x);
        }

        cout << (Kosaraju() ? "YES" : "NO") << endl;
    }
}