#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1], F[n + 1], G[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(F, 0, sizeof(F));
        memset(G, 0, sizeof(G));

        for (int i = 1; i <= n; i++) {
            F[i] = a[i];
            for (int j = 1; j < i; j++) {
                if (a[i] > a[j])
                    F[i] = max(F[i], F[j] + a[i]);
            }
        }

        for (int i = n; i >= 1; i--) {
            G[i] = a[i];
            for (int j = n; j > i; j--) {
                if (a[i] > a[j])
                    G[i] = max(G[i], G[j] + a[i]);
            }
        }

        ll res = 0;
        for (int i = 1; i <= n; i++)
            res = fmax(res, F[i] + G[i] - a[i]);
        cout << res << endl;
    }
}