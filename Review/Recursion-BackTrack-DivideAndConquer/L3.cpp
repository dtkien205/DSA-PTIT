#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e6;
bool check;

ll Pow(ll a, ll b)
{
    if (a >= mod) {
        a %= mod;
        check = 1;
    }

    if (b == 0)
        return 1;

    ll x = Pow(a, b / 2);
    
    if (b % 2 == 0) {
        if (x * x >= mod)
            check = 1;
        return (x * x) % mod;
    } else {
        if (x * x >= mod || (x * x) % mod * a >= mod)
            check = 1;
        return ((x * x) % mod * a) % mod;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll a, b;
    cin >> a >> b;
    ll res = Pow(a, b);
    if (check) {
        string s = to_string(res);
        while (s.size() < 6)
            s = "0" + s;
        cout << s << endl;
    } else
        cout << res;
}