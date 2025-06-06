#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
vector<int> adj[100005];
bool vs[100005];

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
        adj[y].push_back(x);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vs[i]) {
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << endl;
}