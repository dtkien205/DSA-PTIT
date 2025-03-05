#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int mod = 1e9 + 7;

ll Pow(int n, int k)
{
    if (k == 0)
        return 1;
    ll tmp = Pow(n, k / 2);
    if (k % 2 == 0)
        return (tmp * tmp) % mod;
    else
        return ((tmp * tmp) % mod * n) % mod;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << Pow(n, k) << endl;
    }
}