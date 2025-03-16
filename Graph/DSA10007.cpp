#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, s;
vector<int> adj[1005];
bool visited[1005];
vector<pair<int, int>> res;

void BFS(int u)
{
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : adj[x]) {
            if (!visited[y]) {
                visited[y] = true;
                q.push(y);
                res.push_back({ x, y });
            }
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
        BFS(s);
        if (res.size() == n - 1) {
            for (auto [x, y] : res)
                cout << x << ' ' << y << endl;
        } else
            cout << -1 << endl;
    }
}