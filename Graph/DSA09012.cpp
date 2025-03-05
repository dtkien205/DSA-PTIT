#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> ke[1005];
bool visited[1005];
int v, e;

void nhap()
{
    cin >> v >> e;
    memset(visited, false, sizeof(visited));
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
    for (int v : ke[u]) {
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int tplt()
{
    int cnt = 0;
    for (int i = 1; i <= v; i++) {
        if (!visited[i]) {
            cnt++;
            DFS(i);
        }
    }
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        nhap();
        int bd = tplt();
        for (int i = 1; i <= v; i++) {
            memset(visited, false, sizeof(visited));
            visited[i] = true;
            if (tplt() > bd)
                cout << i << ' ';
        }
        cout << endl;
    }
}