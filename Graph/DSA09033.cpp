#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, cnt;
vector<int> adj[100005];
bool visited[100005];

void reset()
{
    cnt = 0;
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
        cin >> n >> m;
        reset();
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i);
            }
        }
        cout << (cnt == 1 ? "YES" : "NO") << endl;
    }
}