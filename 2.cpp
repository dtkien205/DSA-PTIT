#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>

int n, m, s, t, a[1005][1005];
vector<ii> adj[1005];

void dijkstra()
{
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({ 0, s });
    vector<int> d(n + 1, 1e9);
    vector<int> trace(n + 1, -1);
    d[s] = 0;

    while (!q.empty()) {
        auto [dis, u] = q.top();
        q.pop();

        if (dis > d[u])
            continue;

        for (auto [v, w] : adj[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                trace[v] = u;
                q.push({ d[v], v });
            }
        }
    }

    if (d[t] != 1e9) {
        vector<int> path;
        for (int v = t; v != -1; v = trace[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        cout << d[t] << endl;
        for (int v : path)
            cout << v << ' ';
    } else
        cout << 0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    // freopen("DN.INP", "r", stdin);
    // freopen("DN.OUT", "w", stdout);

    cin >> n >> m >> s >> t;

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cin >> a[i][j];
    //         if (a[i][j] > 0 && a[i][j] <= 50) {
    //             adj[i].push_back({ j, a[i][j] });
    //         }
    //     }
    // }
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }

    dijkstra();
}