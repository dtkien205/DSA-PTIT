#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
vector<int> adj[1005];
bool visited[1005], ok;

void reset()
{
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

void dfs(int u, int cnt)
{
    if (ok)
        return;
    if (cnt == n) {
        ok = true;
        return;
    }
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs(v, cnt + 1);
            visited[v] = false;
        }
    }
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
        ok = false;
        for (int i = 1; i <= n; i++) {
            memset(visited, false, sizeof(visited));
            visited[i] = true;
            dfs(i, 1);
            if (ok)
                break;
        }
        cout << (ok ? 1 : 0) << endl;
    }
}