#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
int color[1005];
vector<int> adj[1005];

void reset()
{
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

bool dfs(int u)
{
    color[u] = 1;
    for (int v : adj[u]) {
        if (!color[v]) {
            if (dfs(v))
                return true;
        } else if (color[v] == 1)
            return true;
    }
    color[u] = 2;
    return false;
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
        }
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            if (!color[i]) {
                if (dfs(i)) {
                    ok = true;
                    break;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}