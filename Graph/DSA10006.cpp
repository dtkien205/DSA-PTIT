#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, s;
vector<int> adj[1005];
bool visited[1005];
vector<pair<int, int>> res;

void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            res.push_back({ u, v });
            DFS(v);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> s;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        memset(visited, false, sizeof(visited));
        res.clear();
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        DFS(s);
        if (res.size() == n - 1) {
            for (auto [x, y] : res)
                cout << x << ' ' << y << endl;
        } else
            cout << -1 << endl;
    }
}