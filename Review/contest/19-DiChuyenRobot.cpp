#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int n, xA, yA, xB, yB;
set<pair<int, int>> path, vs;

void bfs()
{
    queue<tuple<int, int, int>> q;
    q.push({ xA, yA, 0 });
    vs.insert({ xA, yA });

    while (!q.empty()) {
        auto [i, j, cnt] = q.front();
        q.pop();

        if (i == xB && j == yB) {
            cout << cnt << endl;
            return;
        }

        for (int k = 0; k < 8; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];

            if (!vs.count({ i1, j1 }) && path.count({ i1, j1 })) {
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
        vs.clear();
        path.clear();

        cin >> xA >> yA >> xB >> yB >> n;
        for (int i = 0; i < n; i++) {
            int x, y1, y2;
            cin >> x >> y1 >> y2;
            for (int y = y1; y <= y2; y++)
                path.insert({ x, y });
        }

        bfs();
    }
}