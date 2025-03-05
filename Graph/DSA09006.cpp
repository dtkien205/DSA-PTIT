#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> ke[1005];
int v, e, s, t;
int parent[1005];
bool visited[1005];
vector<int> res;

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

void nhap()
{
    cin >> v >> e >> s >> t;
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    for (int i = 1; i <= v; i++)
        ke[i].clear();
    res.clear();

    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void path()
{
    DFS(s);
    if (!visited[t])
        cout << "-1\n";
    else {
        while (t != s) {
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
        reverse(res.begin(), res.end());
        for (int x : res)
            cout << x << ' ';
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