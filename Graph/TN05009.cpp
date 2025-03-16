#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m;
bool check[1001];
vector<int> adj[1001];
bool found_cycle;
string result;

void reset()
{
    for (int i = 0; i < 1001; i++) {
        adj[i].clear();
        check[i] = false;
    }
}

void DFS(int u, string path, int parent)
{
    if (found_cycle)
        return;
    check[u] = true;

    for (int v : adj[u]) {
        if (!check[v]) {
            DFS(v, path + " " + to_string(v), u);
        } else if (v != parent && v == 1) {
            found_cycle = true;
            result = path;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        reset();
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; i++)
            sort(adj[i].begin(), adj[i].end());

        found_cycle = false;
        DFS(1, "1", 0);

        if (!found_cycle)
            cout << "NO\n";
        else
            cout << result << " 1\n";
    }
}
