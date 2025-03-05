#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> ke[1005];
bool visited[1005];
int v, e, s, t, parent[1005];

void nhap()
{
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    cin >> v >> e >> s >> t;
    for (int i = 1; i <= v; i++)
        ke[i].clear();
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
    }
    for (int i = 1; i <= v; i++)
        sort(ke[i].begin(), ke[i].end());
}

void DFS(int u)
{
    visited[u] = true;
    for (int v : ke[u]) {
        if (!visited[v]) {
            parent[v] = u;
            DFS(v);
        }
    }
}

void path()
{
    DFS(s);
    if (!visited[t])
        cout << "-1\n";
    else {
        vector<int> res;
        while (t != s) {
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        for (int i = res.size() - 1; i >= 0; i--)
            cout << res[i] << ' ';
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        nhap();
        path();
    }
}