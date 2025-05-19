#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

bool visited[1005];
vector<int> adj[1005];
int n, m, s, t;

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
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m >> s >> t;
        for (int i = 1; i <= n; i++)
            adj[i].clear();

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            memset(visited, false, sizeof(visited));
            visited[i] = true;
            dfs(s);
            if (!visited[t])
                res++;
        }
        cout << res << endl;
    }
}