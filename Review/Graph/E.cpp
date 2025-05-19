#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> adj[1005];
int n, m;
bool vs[1005], inDeg[1005];

void dfs(int u)
{
    vs[u] = true;
    for (int v : adj[u]) {
        if (!vs[v])
            dfs(v);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        inDeg[y] = true;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!inDeg[i] && !vs[i]) {
            res++;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vs[i]) {
            res++;
            dfs(i);
        }
    }
    cout << res << endl;
}