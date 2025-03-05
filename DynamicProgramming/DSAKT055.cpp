#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int F[1005][1005];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, v;
        cin >> n >> v;
        int a[n + 1], c[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        memset(F, 0, sizeof(F));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= v; j++) {
                if (j >= a[i])
                    F[i][j] = max(F[i - 1][j - a[i]] + c[i], F[i - 1][j]);
                else
                    F[i][j] = F[i - 1][j];
            }
        }
        cout << F[n][v] << endl;
    }
}