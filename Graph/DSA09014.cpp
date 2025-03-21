#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
vector<int> adj[1005];
bool visited[1005];
int parent[1005];

bool dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v))
                return true;
        } else if (v != parent[u])
            return true;
    }
    return false;
}

void reset()
{
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        reset();
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool check = false;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (dfs(i)) {
                    cout << "YES\n";
                    check = true;
                    break;
                }
            }
        }
        if (!check)
            cout << "NO\n";
    }
}