#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define iii tuple<int, int, int>

int n;
char a[105][105];

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

int bfs(int s, int t, int u, int v)
{
    queue<iii> q;
    q.push({ s, t, 0 });
    a[s][t] = 'X';
    while (!q.empty()) {
        auto [i, j, cnt] = q.front();
        q.pop();
        if (i == u && j == v)
            return cnt;

        for (int k = 0; k < 4; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            while (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1] == '.') {
                a[i1][j1] = 'X';
                q.push({ i1, j1, cnt + 1 });
                i1 += dx[k], j1 += dy[k];
            }
        }
    }
    return -1;
}

int main()
{
    int x;
    cin >> x;
    while (x--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        int s, t, u, v;
        cin >> s >> t >> u >> v;
        s++, t++, u++, v++;
        cout << bfs(s, t, u, v) << endl;
    }
}