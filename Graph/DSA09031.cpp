#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define iiii tuple<int, int, int, int>

int n, k, m, cnt;
int a[1005][1005];
bool vs[1005][1005];
set<iiii> walls;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    vs[x][y] = true;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int i1 = i + dx[k], j1 = j + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && !vs[i1][j1]) {
                if (walls.count({ i, j, i1, j1 }) || walls.count({ i1, j1, i, j }))
                    continue;
                if (a[i1][j1] == 1)
                    cnt++;
                q.push({ i1, j1 });
                vs[i1][j1] = true;
            }
        }
    }
}

ll count(vector<int> v)
{
    ll d = 0;
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = i + 1; j < v.size(); j++)
            d += 1ll * v[i] * v[j];
    return d;
}

int main()
{
    cin >> n >> k >> m;
    memset(a, 0, sizeof(a));
    memset(vs, false, sizeof(vs));
    for (int i = 0; i < m; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        walls.insert({ u, v, x, y });
        walls.insert({ x, y, u, v });
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }

    vector<int> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 1 && !vs[i][j]) {
                cnt = 1;
                bfs(i, j);
                v.push_back(cnt);
            }
        }
    }
    cout << count(v) << endl;
}