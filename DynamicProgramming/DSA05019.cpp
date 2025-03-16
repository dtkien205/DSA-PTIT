#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n + 1][m + 1], F[n + 1][m + 1];
        memset(a, 0, sizeof(a));
        memset(F, 0, sizeof(F));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j])
                    F[i][j] = min({ F[i - 1][j - 1], F[i][j - 1], F[i - 1][j] }) + 1;
                else
                    F[i][j] = 0;
                res = max(res, F[i][j]);
            }
        }
        cout << res << endl;
    }
}