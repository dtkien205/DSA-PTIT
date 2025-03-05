#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

ll powMod(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll x = powMod(a, b / 2);
    if (b % 2 == 0)
        return (x * x) % mod;
    else
        return ((x * x) % mod * a) % mod;
}

int main()
{
    ll a, b;
    while (1) {
        cin >> a >> b;
        if (!a && !b)
            return 0;
        cout << powMod(a, b) << endl;
    }
}