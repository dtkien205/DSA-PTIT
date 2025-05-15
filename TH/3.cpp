#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int mod = 1e9 + 7;

ll Pow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll x = Pow(a, b / 2);
    if (b % 2 == 0)
        return x * x % mod;
    else
        return ((x * x) % mod * a) % mod;
}

int main()
{
    ll a, b;
    while (1) {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        cout << Pow(a, b) << endl;
    }
}