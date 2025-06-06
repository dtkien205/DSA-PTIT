#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
vector<int> adj[1005];
bool vs1[1005], vs2[1005];
int par1[1005], par2[1005];

void dfs(int u)
{
    vs1[u] = true;
    for (int v : adj[u]) {
        if (!vs1[v]) {
            par1[v] = u;
            dfs(v);
        }
    }
}

void bfs(int u)
{
    vs2[u] = true;
    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y : adj[x]) {
            if (!vs2[y]) {
                vs2[y] = true;
                q.push(y);
                par2[y] = x;
            }
        }
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

    dfs(1);
    bfs(1);

    for (int i = 2; i <= n; i++) {
        if (vs1[1]) {
            vector<int> path;
            int t = i;
            while (t != 1) {
                path.push_back(t);
                t = par1[t];
            }
            path.push_back(1);
            for (int j = path.size() - 1; j >= 0; j--)
                cout << path[j] << ' ';
            cout << endl;
        } else
            cout << -1 << endl;

        if (vs2[1]) {
            vector<int> path;
            int t = i;
            while (t != 1) {
                path.push_back(t);
                t = par2[t];
            }
            path.push_back(1);
            for (int x : path)
                cout << x << ' ';
            cout << endl;
        } else
            cout << -1 << endl;
    }
}