#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int u, v, n;
set<pair<int, int>> blocked, vs;

void bfs()
{
    queue<tuple<int, int, int>> q;
    q.push({ 0, 0, 0 });
    vs.insert({ 0, 0 });

    while (!q.empty()) {
        auto [i, j, cnt] = q.front();
        q.pop();

        if (i == u && j == v) {
            cout << cnt << endl;
            return;
        }

        for (int k = 0; k < 8; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];

            if (i1 >= -1000 && i1 <= 1000 && j1 >= -1000 && j1 <= 1000 && !blocked.count({ i1, j1 }) && !vs.count({ i1, j1 })) {
                vs.insert({ i1, j1 });
                q.push({ i1, j1, cnt + 1 });
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> u >> v >> n;
        blocked.clear();
        vs.clear();
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            blocked.insert({ x, y });
        }
        bfs();
    }
}