#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        bool F[n + 1][s + 1];
        memset(F, false, sizeof(F));

        for (int i = 0; i <= n; i++)
            F[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= s; j++) {
                if (j >= a[i])
                    F[i][j] = F[i - 1][j - a[i]] || F[i - 1][j];
                else
                    F[i][j] = F[i - 1][j];
            }
        }
        if (F[n][s])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}