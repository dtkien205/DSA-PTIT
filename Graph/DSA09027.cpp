#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> ke[1005];
bool visited[1005];
int parent[1005], ID[1005];
int v, e, dem;

void nhap()
{
    dem = 0;
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    cin >> v >> e;
    for (int i = 1; i <= v; i++)
        ke[i].clear();
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}

void DFS(int u)
{
    visited[u] = true;
    ID[u] = dem;
    for (int v : ke[u]) {
        if (!visited[v]) {
            parent[v] = u;
            DFS(v);
        }
    }
}

void checkPath()
{
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            dem++;
            DFS(i);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;
        cout << ((ID[s] == ID[t]) ? "YES\n" : "NO\n");
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        nhap();
        checkPath();
    }
}