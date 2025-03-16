#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, max_height;
vector<int> adj[100005];

void dfs(int u, int par, int cnt)
{
    for (int v : adj[u]) {
        if (v != par) {
            max_height = max(max_height, cnt);
            dfs(v, u, cnt + 1);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        max_height = 0;
        dfs(1, -1, 1);
        cout << max_height << endl;
    }
}