#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define iii tuple<int, int, int>

int n, m;
int a[505][505];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

int bfs()
{
    queue<pair<int, int>> q;
    int totalSeed = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 2)
                q.push({ i, j });
            if (a[i][j] == 1)
                totalSeed++;
        }
    }

    int day = 0;
    while (!q.empty() && totalSeed > 0) {
        int turn = q.size();
        while (turn--) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int i1 = i + dx[k];
                int j1 = j + dy[k];
                if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1) {
                    a[i1][j1] = 2;
                    q.push({ i1, j1 });
                    totalSeed--;
                }
            }
        }
        day++;
    }
    return (totalSeed == 0 ? day : -1);
}

int main()
{
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        cout << bfs() << endl;
    }
}