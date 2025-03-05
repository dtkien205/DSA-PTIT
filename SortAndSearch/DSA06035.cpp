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
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int F[n + 1], G[n + 1];
        fill(F, F + n + 1, 1);
        fill(G, G + n + 1, 1);

        for (int i = 2; i <= n; i++) {
            if (a[i] > a[i - 1])
                F[i] = F[i - 1] + 1;
        }

        for (int i = n - 1; i >= 1; i--) {
            if (a[i] > a[i + 1])
                G[i] = G[i + 1] + 1;
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, F[i] + G[i] - 1);
        }
        cout << res << endl;
    }
}