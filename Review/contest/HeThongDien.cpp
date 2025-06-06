#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> adj[10005];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> power(m);

    for (int i = 0; i < m; i++)
        cin >> power[i];

    for (int i = 0; i < h; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> d(n, 1e9);
    queue<int> q;
    for (auto x : power) {
        d[x] = 0;
        q.push(x);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }

    int maxDis = -1, res = n;
    for (int i = 0; i < n; i++) {
        if (d[i] > maxDis || d[i] == maxDis && i < res) {
            maxDis = d[i];
            res = i;
        }
    }
    cout << res;
}