#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int v, e, u;
vector<int> ke[1005];
bool visited[1005];

void BFS(int u)
{
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int y : ke[x]) {
            if (!visited[y]) {
                visited[y] = true;
                q.push(y);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e >> u;
        for (int i = 1; i <= v; i++)
            ke[i].clear();
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < e; i++) {
            int x, y;
            cin >> x >> y;
            ke[x].push_back(y);
        }
        for (int i = 1; i <= v; i++)
            sort(ke[i].begin(), ke[i].end());

        BFS(u);
        cout << endl;
    }
}