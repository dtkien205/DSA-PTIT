#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define iii tuple<int, int, int>

bool vs[50][50];
int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int bfs(int s, int t, int u, int v)
{
    memset(vs, false, sizeof(vs));
    queue<iii> q;
    q.push({ s, t, 0 });
    vs[s][t] = true;
    while (!q.empty()) {
        auto [i, j, d] = q.front();
        q.pop();
        if (i == u && j == v)
            return d;

        for (int k = 0; k < 8; k++) {
            int i1 = i + dx[k], j1 = j + dy[k];
            if (i1 >= 1 && i1 <= 8 && j1 >= 1 && j1 <= 8 && !vs[i1][j1]) {
                vs[i1][j1] = true;
                q.push({ i1, j1, d + 1 });
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int s = s1[0] - 'a' + 1,
            t = s1[1] - '0',
            u = s2[0] - 'a' + 1,
            v = s2[1] - '0';
        cout << bfs(s, t, u, v) << endl;
    }
}