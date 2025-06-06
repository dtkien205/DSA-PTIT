// D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
vector<int> adj[100005];
vector<pair<int, int>> e;
bool vs[100005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        e.push_back({ x, y });
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll res = LLONG_MAX;

    for (int i = 1; i <= n; i++) {
        if (!vs[i]) {
            auto [f, s] = e[i - 1];
            auto xmin = f, xmax = f;
            auto ymin = s, ymax = s;

            queue<int> q;
            q.push(i);
            vs[i] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();

                auto [x, y] = e[u - 1];
                xmin = min(xmin, x);
                xmax = max(xmax, x);
                ymin = min(ymin, y);
                ymax = max(ymax, y);

                for (int v : adj[u]) {
                    if (!vs[v]) {
                        vs[v] = true;
                        q.push(v);
                    }
                }
            }
            ll S = ((xmax - xmin) + (ymax - ymin)) * 2;
            res = min(res, S);
        }
    }
    cout << res;
}