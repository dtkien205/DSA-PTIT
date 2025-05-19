#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>

int n, m, s, t;
ll d[100005];
vector<ii> adj[100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }

    for (int i = 1; i <= n; i++)
        d[i] = 1e18;

    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({ 0, s });
    d[s] = 0;

    while (!q.empty()) {
        auto [kc, u] = q.top();
        q.pop();

        if (kc > d[u])
            continue;

        for (auto [v, w] : adj[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({ d[v], v });
            }
        }
    }

    cout << d[t];
}