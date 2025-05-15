#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

ll Pow(int a, int b)
{
    if (b == 0)
        return 1;
    ll x = Pow(a, b / 2);
    if (b % 2 == 0)
        return (x * x) % mod;
    else
        return ((x * x) % mod * a) % mod;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int a, b;
        cin >> a >> b;
        cout << Pow(a, b) << endl;
    }
}