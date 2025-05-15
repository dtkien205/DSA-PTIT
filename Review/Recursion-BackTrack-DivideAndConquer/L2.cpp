#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll Mul(ll a, ll b, ll c)
{
    if (b == 0)
        return 0;
    if (b == 1)
        return a;
    ll x = Mul(a, b / 2, c);
    if (b % 2 == 0)
        return (x + x) % c;
    else
        return ((x + x) % c + a) % c;
}

ll Pow(ll a, ll b, ll c)
{
    if (b == 0)
        return 1;
    ll x = Pow(a, b / 2, c);
    if (b % 2 == 0)
        return Mul(x, x, c) % c;
    else
        return Mul(Mul(x, x, c) % c, a, c) % c;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << Pow(a, b, c) << endl;
    }
}