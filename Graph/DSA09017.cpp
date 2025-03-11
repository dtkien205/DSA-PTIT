#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
vector<int> adj[1005];
bool visited[1005];

void reset()
{
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        reset();
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
                cnt++;
            }
        }
        cout << (cnt == 1 ? "YES\n" : "NO\n");
    }
}