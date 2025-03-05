#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int v, e, u;
vector<int> ke[1005];
bool visited[1005];

void DFS(int u)
{
    cout << u << ' ';
    visited[u] = true;
    for (int v : ke[u]) {
        if (!visited[v])
            DFS(v);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        memset(visited, false, sizeof(visited));
        cin >> v >> e >> u;

        for (int i = 1; i <= v; i++)
            ke[i].clear();

        for (int i = 0; i < e; i++) {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }
        DFS(u);
        cout << endl;
    }
}