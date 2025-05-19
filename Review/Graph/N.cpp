#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, sz[100005];
bool vs[100005];
vector<int> adj[100005];

void dfs(int u, int cnt)
{
    vs[u] = true;
    sz[u] = cnt;
    for (int v : adj[u]) {
        if (!vs[v])
            dfs(v, cnt + 1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);
    ll res = 0;
    sort(sz + 1, sz + n + 1);
    for (int i = n; i >= n - k + 1; i--) 
        res += sz[i];
    cout << res;
}