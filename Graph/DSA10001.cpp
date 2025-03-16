#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct node {
    int i, j, dir, cnt;
};

int n, m, s, t, u, v;
char a[505][505];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

bool bfs()
{
    queue<node> q;
    q.push({ s, t, -1, 0 });
    while (!q.empty()) {
        auto [i, j, dir, cnt] = q.front();
        q.pop();
        if (i == u && j == v)
            return true;
        if (cnt > 3)
            continue;
        for (int k = 0; k < 4; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && (a[i1][j1] == '.' || a[i1][j1] == 'T')) {
                int new_cnt = (dir == -1 || dir == k ? cnt : cnt + 1);
                a[i1][j1] = '*';
                q.push({ i1, j1, k, new_cnt });
            }
        }
    }
    return false;
}

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                s = i;
                t = j;
            }
            if (a[i][j] == 'T') {
                u = i;
                v = j;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        input();
        cout << (bfs() ? "YES\n" : "NO\n");
    }
}
