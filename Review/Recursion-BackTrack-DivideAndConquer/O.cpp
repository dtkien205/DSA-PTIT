#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll Pow(int a, int b, int mod)
{
    if (b == 0)
        return 1;
    ll x = Pow(a, b / 2,mod);
    if (b % 2 == 0)
        return (x * x) % mod;
    else
        return ((x * x) % mod * a) % mod;
}

ll cal(int a, int n, int m)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0) {
        ll x = cal(a, n / 2 - 1, m);
        return (x * Pow(a, n / 2, m) + x + Pow(a, n, m)) % m;
    } else {
        ll x = cal(a, n / 2, m);
        return (x + x * Pow(a, n / 2 + 1, m)) % m;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int a, n, m;
    cin >> a >> n >> m;
    cout << cal(a, n, m);
}