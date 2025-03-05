#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> ke[1005];
bool visited[1005];
int parent[1005];
int v, e, s, t;
vector<int> res;

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : ke[x]) {
            if (!visited[y]) {
                visited[y] = true;
                q.push(y);
                parent[y] = x;
            }
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
    BFS(s);
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