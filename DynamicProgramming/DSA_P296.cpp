#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int n, q;
    cin >> n >> q;
    ll a[n + 1], F[n + 1];
    F[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        F[i] = 0;
        if (a[i] < 0)
            a[i] = 0;
        F[i] = F[i - 1] + a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << F[r] - F[l - 1] << endl;
    }
}