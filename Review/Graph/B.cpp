#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

set<int> adj[1005];
bool visited[1005];
int n;

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
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i < j && a[i][j]) {
                adj[i].insert(j);
                adj[j].insert(i);
            }
        }
    }

    int bd = tplt(), res = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i < j && a[i][j]) {
                memset(visited, false, sizeof(visited));
                adj[i].erase(j);
                adj[j].erase(i);
                if (tplt() > bd)
                    res++;
                adj[i].insert(j);
                adj[j].insert(i);
            }
        }
    }
    cout << res << endl;
}
