#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;
int n, k;

struct matrix {
    ll f[10][10];
};

matrix operator*(matrix a, matrix b)
{
    matrix c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c.f[i][j] = 0;
            for (int k = 0; k < n; k++)
                c.f[i][j] = (c.f[i][j] + a.f[i][k] * b.f[k][j] % mod) % mod;
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

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << powMod(a, k).f[i][j] << " ";
            cout << endl;
        }
    }
}