#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<int> ke[1005];
bool visited[1005];
int v, e;

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
            }
        }
    }
}

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

int main()
{
    int t;
    cin >> t;
    while (t--) {
        nhap();
        int dem = 0;
        for (int i = 1; i <= v; i++) {
            if (!visited[i]) {
                BFS(i);
                dem++;
            }
        }
        cout << dem << endl;
    }
}