#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int v, e;
set<int> ke[1005];
vector<pair<int, int>> canh, res;
bool visited[1005];

void nhap()
{
    cin >> v >> e;
    res.clear();
    for (int i = 1; i <= v; i++)
        ke[i].clear();
    memset(visited, false, sizeof(visited));
    canh.clear();

    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        canh.push_back({ x, y });
        ke[x].insert(y);
        ke[y].insert(x);
    }
}

void DFS(int u)
{
    visited[u] = true;
    for (int v : ke[u]) {
        if (!visited[v])
            DFS(v);
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

void CanhCau()
{
    int bd = tplt();
    for (auto it : canh) {
        int x = it.first, y = it.second;
        ke[x].erase(y);
        ke[y].erase(x);
        memset(visited, false, sizeof(visited));
        if (bd < tplt())
            res.push_back({ x, y });

        ke[x].insert(y);
        ke[y].insert(x);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        nhap();
        CanhCau();
        for (auto x : res)
            cout << x.first << ' ' << x.second << ' ';
        cout << endl;
    }
}