#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;
int n, k;

struct matrix {
    ll f[11][11];
};

matrix operator*(matrix a, matrix b)
{
    matrix c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c.f[i][j] = 0;
            for (int u = 0; u < n; u++) {
                c.f[i][j] += (1ll * (a.f[i][u] % mod) * (b.f[u][j] % mod)) % mod;
                c.f[i][j] %= mod;
            }
        }
    }
    return c;
}

matrix powMod(matrix a, int n)
{
    if (n == 1)
        return a;
    matrix x = powMod(a, n / 2);
    if (n % 2 == 0)
        return x * x;
    else
        return x * x * a;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        matrix a;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a.f[i][j];
        matrix res = powMod(a, k);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            // cout << res.f[n - 1][i] << endl;
            ans += res.f[i][n - 1];
            ans %= mod;
        }
        cout << ans << endl;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++)
        //         cout << res.f[i][j] << ' ';
        //     cout << endl;
        // }
    }
}