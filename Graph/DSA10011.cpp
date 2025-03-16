#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define iii tuple<int, int, int>

int n, m, a[505][505], d[505][505];
bool visited[505][505];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void input()
{
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            d[i][j] = INT_MAX;
        }
    }
}

void Dijkstra()
{
    d[1][1] = a[1][1];
    priority_queue<iii, vector<iii>, greater<iii>> q;
    q.push({ d[1][1], 1, 1 });
    while (!q.empty()) {
        auto [kc, i, j] = q.top();
        q.pop();
        if (visited[i][j])
            continue;
        visited[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m) {
                if (d[i1][j1] > d[i][j] + a[i1][j1]) {
                    d[i1][j1] = d[i][j] + a[i1][j1];
                    q.push({ d[i1][j1], i1, j1 });
                }
            }
        }
    }
    cout << d[n][m] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        input();
        Dijkstra();
    }
}