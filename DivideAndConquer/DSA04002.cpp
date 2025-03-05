#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

ll Pow(ll n, ll k)
{
    if (k == 0)
        return 1;
    ll x = Pow(n, k / 2);
    if (k % 2 == 0)
        return (x * x) % mod;
    else
        return ((x * x) % mod * n) % mod;
}

ll lat(ll n)
{
    ll tmp = 0;
    while (n) {
        tmp = tmp * 10 + n % 10;
        n /= 10;
    }
    return tmp;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << Pow(n, lat(n)) << endl;
    }
}