#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[20][20], ok;

void Try(int i, int j, string path)
{
    if (!a[1][1])
        return;
    if (i == n && j == n) {
        cout << path << " ";
        ok = 0;
        return;
    }
    if (i + 1 <= n && a[i + 1][j])
        Try(i + 1, j, path + "D");
    if (j + 1 <= n && a[i][j + 1])
        Try(i, j + 1, path + "R");
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ok = 1;
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        Try(1, 1, "");
        if (ok || !a[1][1])
            cout << "-1";
        cout << endl;
    }
}