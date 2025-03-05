#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int v, e;
vector<int> ke[1005];
bool visited[1005];

void DFS(int u)
{
    visited[u] = true;
    for (int v : ke[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        for (int i = 1; i <= v; i++)
            ke[i].clear();
        memset(visited, false, sizeof(visited));

        for (int i = 1; i <= e; i++) {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
            ke[y].push_back(x);
        }

        int dem = 0;
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) {
                dem++;
                DFS(i);
            }
        }
        cout << dem << endl;
    }
}