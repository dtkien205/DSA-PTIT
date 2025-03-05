#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 123456789;

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

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << Pow(2, n - 1) << endl;
    }
}