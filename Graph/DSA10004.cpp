#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, deg[1005];
vector<int> adj[1005];
bool visited[1005], ok;

void reset()
{
    memset(visited, false, sizeof(visited));
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    ok = false;
}

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

bool tplt()
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

int check()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 == 1)
            cnt++;
    }
    return cnt;
}

int solve()
{
    int lt = tplt();
    int tmp = check();
    if (lt == 1 && !tmp)
        return 2;
    else if (lt == 1 && tmp == 2)
        return 1;
    return 0;
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
            deg[x]++;
            deg[y]++;
        }
        cout << solve() << endl;
    }
}