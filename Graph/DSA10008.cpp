#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define ii pair<int, int>

int n, m, s;
vector<ii> adj[1005];

void input()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
    }
}

void Dijkstra()
{
    vector<int> d(n + 1, 1e9);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    d[s] = 0;
    pq.push({ 0, s });
    while (!pq.empty()) {
        auto [kc, u] = pq.top();
        pq.pop();
        if (kc > d[u])
            continue;
        for (auto [v, w] : adj[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({ d[v], v });
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        input();
        Dijkstra();
    }
}