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
        int a[n + 1][m + 1];
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1)
                    a[i][j] += a[i][j - 1];
                else if (j == 1)
                    a[i][j] += a[i - 1][j];
                else
                    a[i][j] += min({ a[i - 1][j], a[i - 1][j - 1], a[i][j - 1] });
            }
        }
        cout << a[n][m] << endl;
    }
}