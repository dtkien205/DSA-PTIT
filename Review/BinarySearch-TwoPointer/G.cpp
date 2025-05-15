#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n, s;
    cin >> n >> s;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll res = INT_MAX, sum = 0, l = 1;
    for (int r = 1; r <= n; r++) {
        sum += a[r];
        while (sum >= s && l <= r) {
            res = min(res, r - l + 1);
            sum -= a[l];
            l++;
        }
    }
    cout << (res == INT_MAX ? -1 : res);
}
