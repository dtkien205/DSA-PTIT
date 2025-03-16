#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
vector<int> adj[1005];
bool visited[1005];

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int tplt()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int bd = tplt(), res = 0;
        for (int i = 1; i <= n; i++) {
            memset(visited, false, sizeof(visited));
            visited[i] = true;
            if (bd < tplt())
                cout << i << ' ';
        }
        cout << endl;
    }
}