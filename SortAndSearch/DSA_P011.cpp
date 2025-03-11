#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, cnt;
char a[1005][1005];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void dfs(int i, int j)
{
    a[i][j] = '.';
    for (int k = 0; k < 4; k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == '#')
            dfs(i1, j1);
    }
}

void input()
{
    cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
}

int main()
{
    input();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '#') {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << endl;
}