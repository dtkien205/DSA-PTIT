#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

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

        ll F[n + 1][v + 1];
        memset(F, 0, sizeof(F));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= v; j++) {
                if (j >= a[i])
                    F[i][j] = fmax(F[i - 1][j - a[i]] + c[i], F[i - 1][j]);
                else
                    F[i][j] = F[i - 1][j];
            }
        }
        cout << F[n][v] << endl;
    }
}