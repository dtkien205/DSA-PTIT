#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, m;
bool isExit[100005];
int path[100005];
vector<int> adj[100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        path[i] = 1e9;

    queue<int> q;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        isExit[x] = true;
        path[x] = 0;
        q.push(x);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!isExit[v] && path[u] + 1 < path[v]) {
                path[v] = path[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << path[i] << ' ';
}