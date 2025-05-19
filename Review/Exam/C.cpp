#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, u, v, parent[1005];
vector<int> adj[1005];
bool visited[1005];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    parent[u] = -1;
    visited[u] = true;
    while (!q.empty()) {
        int top = q.front();
        q.pop();

        if (top == v)
            break;

        for (int y : adj[top]) {
            if (!visited[y]) {
                visited[y] = true;
                parent[y] = top;
                q.push(y);
            }
        }
    }
    if (visited[v]) {
        int res = 0;
        while (v != u) {
            res++;
            v = parent[v];
        }
        cout << res << endl;
    } else
        cout << -1 << endl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m >> u >> v;
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= n; i++)
            adj[i].clear();

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        bfs(u);
    }
}