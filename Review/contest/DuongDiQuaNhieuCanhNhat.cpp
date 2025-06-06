#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, cnt, res;
vector<int> adj[50];
bool visited[50][50];

void dfs(int u, int len = 0)
{
    res = max(res, len);
    for (int v : adj[u]) {
        if (!visited[u][v]) {
            visited[u][v] = visited[v][u] = true;
            dfs(v, len + 1);
            visited[u][v] = visited[v][u] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            adj[i].clear();
        res = 0;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 0; i < n; i++)
            dfs(i);
        cout << res << endl;
    }
}