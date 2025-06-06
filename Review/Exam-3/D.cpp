#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, inDeg[1005];
vector<int> adj[1005];
bool vs[1005];

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
        inDeg[y]++;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!inDeg[i]) {
            cnt++;
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vs[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
}