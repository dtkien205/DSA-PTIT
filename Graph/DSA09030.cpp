#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
vector<int> adj[1005];
int color[1005];

void reset()
{
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

bool dfs(int u)
{
    for (int v : adj[u]) {
        if (!color[v]) {
            color[v] = 3 - color[u];
            dfs(v);
        } else if (color[v] == color[u])
            return false;
    }
    return true;
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
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            if (!color[i]) {
                color[i] = 1;
                if (!dfs(i)) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}