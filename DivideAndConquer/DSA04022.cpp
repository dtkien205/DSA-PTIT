#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int res(ll n, ll k)
{
    int x = pow(2, n - 1);
    if (k == x)
        return n;
    if (k <= x)
        return res(n - 1, k);
    else
        return res(n - 1, k - x);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << char(res(n, k) + 'A' - 1) << endl;
    }
}