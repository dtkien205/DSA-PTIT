#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int k, m, n;
set<string> se;
vector<string> res;
char a[5][5];
int visited[5][5];
string s = "";
bool check;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void Try(int i, int j)
{
    s += a[i][j];
    visited[i][j] = 1;

    if (se.count(s)) {
        check = true;
        res.push_back(s);
    }

    for (int k = 0; k < 8; k++) {
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && !visited[i1][j1])
            Try(i1, j1);
    }
    visited[i][j] = 0;
    s.pop_back();
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        res.clear();
        se.clear();
        cin >> k >> n >> m;
        for (int i = 0; i < k; i++) {
            string s;
            cin >> s;
            se.insert(s);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        memset(visited, 0, sizeof(visited));
        check = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                Try(i, j);
            }
        }
        if (!check)
            cout << "-1\n";
        else {
            for (auto x : res)
                cout << x << ' ';
            cout << endl;
        }
    }
}